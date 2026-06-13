#!/usr/bin/env python3

"""
Utilitário para analisar informações dos grafos gerados.
Fornece estatísticas sobre os grafos em cada topologia.
"""

import json
from pathlib import Path
from collections import defaultdict

def analyze_graphs():
    """Analisa os grafos gerados e exibe estatísticas."""
    
    output_dir = Path(__file__).parent / "grafos_gerados"
    
    if not output_dir.exists():
        print("❌ Nenhum grafo gerado ainda. Execute generate_graphs.py ou generate_graphs_advanced.py primeiro.")
        return
    
    log_file = output_dir / "generation_log.json"
    
    if not log_file.exists():
        print("❌ Arquivo de log não encontrado. Verifique se os grafos foram gerados corretamente.")
        return
    
    try:
        with open(log_file, 'r') as f:
            stats = json.load(f)
    except Exception as e:
        print(f"❌ Erro ao ler arquivo de log: {e}")
        return
    
    print("\n" + "="*80)
    print("ANÁLISE DOS GRAFOS GERADOS")
    print("="*80 + "\n")
    
    print(f"Data de geração: {stats.get('timestamp', 'N/A')}")
    print(f"Total de grafos: {stats.get('total', 0)}")
    print(f"Grafos bem-sucedidos: {stats.get('successful', 0)}")
    print(f"Taxa de sucesso: {stats.get('success_rate', 'N/A')}")
    
    print("\n" + "-"*80)
    print("ESTATÍSTICAS POR TOPOLOGIA")
    print("-"*80 + "\n")
    
    for topology_name, topology_data in stats.get('topologies', {}).items():
        print(f"\n📊 Topologia: {topology_name.upper()}")
        print(f"   Descrição: {topology_data.get('description', 'N/A')}")
        print(f"   Parâmetros: {topology_data.get('params', [])}")
        
        graphs = topology_data.get('graphs', [])
        if graphs:
            print(f"\n   {'Nós':<8} {'Arestas':<12} {'Tamanho':<12} {'Arquivo':<40}")
            print(f"   {'-'*75}")
            
            total_size = 0
            for graph in graphs:
                nodes = graph.get('nodes', 0)
                edges = graph.get('edges', 0)
                size = graph.get('size_kb', 0)
                filename = graph.get('filename', 'N/A')
                
                total_size += size
                print(f"   {nodes:<8} {edges:<12} {size:<10.2f} KB  {filename:<40}")
            
            avg_nodes = sum(g.get('nodes', 0) for g in graphs) / len(graphs)
            avg_edges = sum(g.get('edges', 0) for g in graphs) / len(graphs)
            
            print(f"   {'-'*75}")
            print(f"   Média de nós: {avg_nodes:.0f}")
            print(f"   Média de arestas: {avg_edges:.0f}")
            print(f"   Tamanho total: {total_size:.2f} MB")
        else:
            print("   Nenhum grafo gerado para esta topologia.")
    
    print("\n" + "="*80 + "\n")

def list_graph_files():
    """Lista todos os arquivos de grafos gerados."""
    
    output_dir = Path(__file__).parent / "grafos_gerados"
    
    if not output_dir.exists():
        print("❌ Diretório de grafos não encontrado.")
        return
    
    print("\n" + "="*80)
    print("ARQUIVOS DE GRAFOS GERADOS")
    print("="*80 + "\n")
    
    graph_files = defaultdict(list)
    
    for topology_dir in output_dir.iterdir():
        if topology_dir.is_dir() and topology_dir.name != "__pycache__":
            for graph_file in topology_dir.glob("*.txt"):
                graph_files[topology_dir.name].append(graph_file)
    
    if not graph_files:
        print("Nenhum grafo encontrado.")
        return
    
    for topology_name in sorted(graph_files.keys()):
        files = sorted(graph_files[topology_name])
        print(f"\n📁 {topology_name.upper()} ({len(files)} grafos)")
        print("-" * 80)
        
        for filepath in files:
            size = filepath.stat().st_size / 1024
            print(f"   {filepath.name:<50} {size:>10.2f} KB")
    
    print("\n" + "="*80 + "\n")

if __name__ == "__main__":
    print("\nExecutando análise dos grafos gerados...")
    analyze_graphs()
    list_graph_files()
