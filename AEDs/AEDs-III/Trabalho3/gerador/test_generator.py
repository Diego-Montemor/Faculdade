#!/usr/bin/env python3

"""
Script de teste rápido para demonstrar a geração de grafos.
Gera um número pequeno de grafos para validação rápida.
"""

import os
import sys
import subprocess
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

def quick_test():
    """Executa um teste rápido com poucos grafos."""
    
    output_dir = Path(__file__).parent / "grafos_gerados_teste"
    output_dir.mkdir(exist_ok=True)
    
    print("\n" + "="*70)
    print("TESTE RÁPIDO DO GERADOR DE GRAFOS")
    print("="*70 + "\n")
    
    # Configuração para teste: 2 topologias, 3 tamanhos cada
    test_config = {
        "erdos": {"params": [0.1], "description": "Erdős-Rényi"},
        "barabasi": {"params": [3], "description": "Barabási-Albert"}
    }
    
    node_sizes = [100, 200, 300]  # Tamanhos pequenos para teste rápido
    
    total = len(test_config) * len(node_sizes)
    successful = 0
    
    for topology_name, config in test_config.items():
        print(f"Gerando grafos {topology_name} ({config['description']})...")
        
        topology_dir = output_dir / topology_name
        topology_dir.mkdir(exist_ok=True)
        
        for idx, num_nodes in enumerate(node_sizes, 1):
            filename = f"{topology_name}_{num_nodes}_test.txt"
            filepath = topology_dir / filename
            
            args = [
                sys.executable,
                str(Path(__file__).parent / "generator.py"),
                topology_name,
                str(num_nodes)
            ] + [str(p) for p in config['params']]
            
            try:
                print(f"  [{idx}/{len(node_sizes)}] {num_nodes} nós... ", end="", flush=True)
                
                with open(filepath, 'w') as f:
                    result = subprocess.run(args, stdout=f, stderr=subprocess.PIPE, timeout=30)
                
                if result.returncode == 0:
                    size_kb = filepath.stat().st_size / 1024
                    with open(filepath, 'r') as f:
                        n, m = map(int, f.readline().split())
                    print(f"✓ ({n} nós, {m} arestas, {size_kb:.1f} KB)")
                    successful += 1
                else:
                    print("✗")
                    filepath.unlink()
            except Exception as e:
                print(f"✗ ({e})")
                if filepath.exists():
                    filepath.unlink()
        
        print()
    
    print("="*70)
    print(f"Resultado: {successful}/{total} grafos gerados com sucesso")
    print(f"Arquivos salvos em: {output_dir}")
    print("="*70 + "\n")
    print("✅ Teste concluído! Agora execute:\n")
    print("   • generate_graphs.py - Gera 30 grafos (30 minutos)")
    print("   • generate_graphs_advanced.py - Versão customizável")
    print("   • analyze_graphs.py - Analisa os grafos gerados\n")

if __name__ == "__main__":
    quick_test()
