#!/usr/bin/env python3

"""
Script alternativo para gerar grafos com configuração customizável.
Permite escolher topologias, número de grafos e tamanhos.
"""

import os
import sys
import subprocess
import json
from pathlib import Path
from datetime import datetime

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

class GraphGenerator:
    """Classe para gerenciar a geração de grafos."""
    
    def __init__(self):
        self.output_dir = Path(__file__).parent / "grafos_gerados"
        self.output_dir.mkdir(exist_ok=True)
        self.log_file = self.output_dir / "generation_log.json"
        self.generation_stats = {
            "timestamp": datetime.now().isoformat(),
            "topologies": {}
        }
    
    def generate_graph(self, topology, num_nodes, params, output_path):
        """
        Gera um único grafo usando o generator.py.
        
        Args:
            topology (str): Nome da topologia
            num_nodes (int): Número de nós
            params (list): Parâmetros adicionais
            output_path (Path): Caminho do arquivo de saída
        
        Returns:
            bool: True se bem-sucedido, False caso contrário
        """
        args = [
            sys.executable,
            str(Path(__file__).parent / "generator.py"),
            topology,
            str(num_nodes)
        ] + [str(p) for p in params]
        
        try:
            with open(output_path, 'w') as f:
                result = subprocess.run(
                    args,
                    stdout=f,
                    stderr=subprocess.PIPE,
                    timeout=120,
                    text=True
                )
            
            if result.returncode == 0:
                return True
            else:
                if output_path.exists():
                    output_path.unlink()
                return False
        except Exception as e:
            if output_path.exists():
                output_path.unlink()
            return False
    
    def generate_batch(self, topologies_config, num_graphs_per_size=10):
        """
        Gera um lote de grafos com múltiplas topologias.
        
        Args:
            topologies_config (dict): Configuração das topologias
            num_graphs_per_size (int): Número de grafos por tamanho
        """
        # Tamanhos padrão
        node_sizes = [500, 1000, 1500, 2000, 2500, 3000, 4000, 5000, 7500, 10000]
        
        total = len(topologies_config) * len(node_sizes)
        count = 0
        successful = 0
        
        print("\n" + "="*80)
        print("GERADOR CUSTOMIZÁVEL DE GRAFOS")
        print("="*80 + "\n")
        
        for topology_name, topology_config in topologies_config.items():
            print(f"\n📊 Topologia: {topology_name.upper()}")
            print(f"   Descrição: {topology_config['description']}")
            print(f"   Parâmetros: {topology_config['params']}")
            print(f"   {'-'*76}")
            
            topology_dir = self.output_dir / topology_name
            topology_dir.mkdir(exist_ok=True)
            
            self.generation_stats["topologies"][topology_name] = {
                "description": topology_config['description'],
                "params": topology_config['params'],
                "graphs": []
            }
            
            topology_success = 0
            
            for idx, num_nodes in enumerate(node_sizes, 1):
                count += 1
                filename = f"{topology_name}_{num_nodes}_n{idx}.txt"
                filepath = topology_dir / filename
                
                print(f"   [{idx:2d}/{len(node_sizes)}] {num_nodes:5d} nós... ", end="", flush=True)
                
                if self.generate_graph(topology_name, num_nodes, topology_config['params'], filepath):
                    if filepath.exists():
                        size_kb = filepath.stat().st_size / 1024
                        print(f"✓ ({size_kb:.1f} KB)")
                        successful += 1
                        topology_success += 1
                        
                        # Contar arestas
                        with open(filepath, 'r') as f:
                            first_line = f.readline().strip()
                            n, m = map(int, first_line.split())
                        
                        self.generation_stats["topologies"][topology_name]["graphs"].append({
                            "filename": filename,
                            "nodes": n,
                            "edges": m,
                            "size_kb": round(size_kb, 2)
                        })
                    else:
                        print("✗ (Arquivo não gerado)")
                else:
                    print("✗")
            
            print(f"   Resumo: {topology_success}/{len(node_sizes)} grafos gerados com sucesso")
        
        # Salvar estatísticas
        self.save_statistics(successful, total)
        self.print_summary(successful, total)
    
    def save_statistics(self, successful, total):
        """Salva estatísticas em arquivo JSON."""
        self.generation_stats["successful"] = successful
        self.generation_stats["total"] = total
        self.generation_stats["success_rate"] = f"{100*successful/total:.1f}%"
        
        with open(self.log_file, 'w') as f:
            json.dump(self.generation_stats, f, indent=2)
    
    def print_summary(self, successful, total):
        """Imprime resumo da geração."""
        print("\n" + "="*80)
        print("RESUMO FINAL")
        print("="*80)
        print(f"Total de grafos solicitados: {total}")
        print(f"Grafos gerados com sucesso: {successful}")
        print(f"Taxa de sucesso: {100*successful/total:.1f}%")
        print(f"\n📁 Grafos salvos em: {self.output_dir}")
        print(f"📊 Estatísticas salvas em: {self.log_file}")
        print("="*80 + "\n")

def main():
    """Função principal."""
    
    # Configuração padrão recomendada (conforme PDF)
    topologies = {
        "erdos": {
            "description": "Grafo Erdős-Rényi (aleatório)",
            "params": [0.1]
        },
        "barabasi": {
            "description": "Grafo Barabási-Albert (sem escala)",
            "params": [3]
        },
        "watts": {
            "description": "Grafo Watts-Strogatz (mundo pequeno)",
            "params": [4, 0.3]
        }
    }
    
    generator = GraphGenerator()
    generator.generate_batch(topologies)

if __name__ == "__main__":
    main()
