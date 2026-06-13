#!/usr/bin/env python3

"""
Menu interativo para escolher qual script executar.
Facilita o uso dos ferramentas de geração de grafos.
"""

import os
import sys
import subprocess
from pathlib import Path

def print_menu():
    """Exibe o menu interativo."""
    print("\n" + "="*80)
    print("🔬 GERADOR DE GRAFOS - MENU PRINCIPAL".center(80))
    print("="*80 + "\n")
    
    print("Escolha uma opção:\n")
    print("  1️⃣  Teste Rápido (6 grafos pequenos) - ~2-3 minutos")
    print("  2️⃣  Gerar Todos os Grafos (30 grafos) - ~30-45 minutos")
    print("  3️⃣  Gerar Grafos (versão customizável)")
    print("  4️⃣  Analisar Grafos Gerados")
    print("  5️⃣  Mostrar Guia Completo")
    print("  0️⃣  Sair")
    print("\n" + "-"*80)

def run_script(script_name):
    """Executa um script Python."""
    script_path = Path(__file__).parent / script_name
    
    if not script_path.exists():
        print(f"\n❌ Erro: {script_name} não encontrado!")
        return False
    
    try:
        subprocess.run([sys.executable, str(script_path)])
        return True
    except KeyboardInterrupt:
        print("\n\n⚠️  Execução interrompida pelo usuário.")
        return False
    except Exception as e:
        print(f"\n❌ Erro ao executar script: {e}")
        return False

def show_guide():
    """Exibe o guia completo."""
    guide_path = Path(__file__).parent / "GUIA_COMPLETO.md"
    
    if not guide_path.exists():
        print("\n❌ Guia completo não encontrado!")
        return
    
    try:
        with open(guide_path, 'r', encoding='utf-8') as f:
            content = f.read()
        print("\n" + content)
        input("\nPressione ENTER para voltar ao menu...")
    except Exception as e:
        print(f"\n❌ Erro ao ler guia: {e}")

def main():
    """Função principal do menu."""
    
    while True:
        print_menu()
        
        try:
            choice = input("Digite sua escolha (0-5): ").strip()
        except KeyboardInterrupt:
            print("\n\n👋 Saindo...")
            sys.exit(0)
        except EOFError:
            print("\n\n👋 Saindo...")
            sys.exit(0)
        
        if choice == "1":
            print("\n⏱️  Iniciando teste rápido...")
            run_script("test_generator.py")
            input("\nPressione ENTER para voltar ao menu...")
        
        elif choice == "2":
            print("\n⏱️  Iniciando geração de grafos...")
            print("⚠️  Isso pode levar 30-45 minutos. Não interrompa!\n")
            run_script("generate_graphs.py")
            input("\nPressione ENTER para voltar ao menu...")
        
        elif choice == "3":
            print("\n⏱️  Iniciando gerador customizável...")
            run_script("generate_graphs_advanced.py")
            input("\nPressione ENTER para voltar ao menu...")
        
        elif choice == "4":
            print("\n📊 Analisando grafos...")
            run_script("analyze_graphs.py")
            input("\nPressione ENTER para voltar ao menu...")
        
        elif choice == "5":
            show_guide()
        
        elif choice == "0":
            print("\n👋 Saindo...")
            break
        
        else:
            print("\n❌ Opção inválida! Digite um número entre 0 e 5.")
            input("\nPressione ENTER para tentar novamente...")

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\n\n👋 Programa interrompido.")
        sys.exit(0)
