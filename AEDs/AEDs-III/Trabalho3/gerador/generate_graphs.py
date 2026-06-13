#!/usr/bin/env python3

"""
Script para gerar múltiplos grafos para análise de algoritmos de caminho mais curto.
Gera ao menos 3 topologias diferentes com 10+ grafos cada, entre 500 e 10000 vértices.
"""

import os
import sys
import subprocess
from pathlib import Path

# Adiciona o diretório gerador ao path para importar o generator
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

def create_output_directory():
    """Cria o diretório de saída para os grafos gerados."""
    output_dir = Path(__file__).parent / "grafos_gerados"
    output_dir.mkdir(exist_ok=True)
    return output_dir

def generate_graphs():
    """
    Gera múltiplos grafos de diferentes topologias.
    
    Configuração:
    - 3 topologias: erdos, barabasi, watts
    - 10 grafos por topologia
    - Tamanhos variados entre 500 e 10000 vértices
    """
    
    output_dir = create_output_directory()
    
    # Configuração das topologias a serem geradas
    # Cada topologia é um dicionário com: nome, argumentos
    topologies = {
        "erdos": {
            "params": [0.1],  # probabilidade p
            "description": "Grafo Erdős-Rényi"
        },
        "barabasi": {
            "params": [3],  # número de arestas por novo nó
            "description": "Grafo Barabási-Albert"
        },
        "watts": {
            "params": [4, 0.3],  # k vizinhos, probabilidade rewire
            "description": "Grafo Watts-Strogatz"
        }
    }
    
    # Tamanhos de nós para gerar (10 grafos entre 500 e 10000)
    node_counts = [500, 1000, 1500, 2000, 2500, 3000, 4000, 5000, 7500, 10000]
    
    total_graphs = 0
    successful = 0
    failed = 0
    
    print("=" * 70)
    print("GERADOR DE GRAFOS PARA ANÁLISE DE ALGORITMOS DE CAMINHO MAIS CURTO")
    print("=" * 70)
    print()
    
    # Itera sobre cada topologia
    for topology_name, topology_info in topologies.items():
        print(f"\n{'='*70}")
        print(f"Gerando grafos da topologia: {topology_name.upper()}")
        print(f"Descrição: {topology_info['description']}")
        print(f"{'='*70}")
        
        topology_dir = output_dir / topology_name
        topology_dir.mkdir(exist_ok=True)
        
        # Gera 10 grafos de cada tamanho
        for idx, num_nodes in enumerate(node_counts, 1):
            total_graphs += 1
            graph_filename = f"{topology_name}_{num_nodes}_n{idx}.txt"
            graph_path = topology_dir / graph_filename
            
            # Prepara os argumentos para o gerador
            args = [
                sys.executable,  # python3
                str(Path(__file__).parent / "generator.py"),
                topology_name,
                str(num_nodes)
            ]
            
            # Adiciona parâmetros específicos da topologia
            args.extend([str(p) for p in topology_info['params']])
            
            try:
                print(f"  [{idx:2d}/10] Gerando {num_nodes:5d} nós... ", end="", flush=True)
                
                # Executa o gerador e salva a saída
                with open(graph_path, 'w') as f:
                    result = subprocess.run(
                        args,
                        stdout=f,
                        stderr=subprocess.PIPE,
                        timeout=60,
                        text=True
                    )
                
                if result.returncode == 0:
                    file_size = graph_path.stat().st_size / 1024  # KB
                    print(f"✓ ({file_size:.1f} KB)")
                    successful += 1
                else:
                    print(f"✗ (Erro: {result.stderr})")
                    graph_path.unlink()  # Remove arquivo de erro
                    failed += 1
                    
            except subprocess.TimeoutExpired:
                print(f"✗ (Timeout)")
                graph_path.unlink() if graph_path.exists() else None
                failed += 1
            except Exception as e:
                print(f"✗ (Exceção: {e})")
                graph_path.unlink() if graph_path.exists() else None
                failed += 1
        
        print(f"  Resumo da topologia '{topology_name}': {successful - (failed - (total_graphs - idx))} gerados com sucesso")
    
    # Resumo final
    print(f"\n{'='*70}")
    print("RESUMO FINAL")
    print(f"{'='*70}")
    print(f"Total de grafos solicitados: {total_graphs}")
    print(f"Grafos gerados com sucesso: {successful}")
    print(f"Grafos que falharam: {failed}")
    print(f"Taxa de sucesso: {100*successful/total_graphs:.1f}%")
    print(f"\nGrafos salvos em: {output_dir}")
    print()

if __name__ == "__main__":
    generate_graphs()
