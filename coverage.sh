#!/bin/bash

# Script para gerar relatórios de cobertura de testes
# Uso: ./coverage.sh [clean|install|run|open]

set -e

COVERAGE_DIR="coverage"
HTML_DIR="$COVERAGE_DIR/html"

case "${1:-run}" in
    "install")
        echo "🔧 Instalando ferramentas de cobertura..."
        if command -v brew >/dev/null 2>&1; then
            brew install lcov
            echo "✅ lcov instalado com sucesso!"
        else
            echo "❌ Homebrew não encontrado. Instale o lcov manualmente:"
            echo "   - macOS: brew install lcov"
            echo "   - Ubuntu: sudo apt-get install lcov"
            echo "   - CentOS: sudo yum install lcov"
            exit 1
        fi
        ;;
    
    "clean")
        echo "🧹 Limpando arquivos de cobertura..."
        make clean-coverage
        echo "✅ Arquivos de cobertura removidos!"
        ;;
    
    "run")
        echo "🧪 Executando testes com cobertura..."
        
        # Verifica se lcov está instalado
        if ! command -v lcov >/dev/null 2>&1; then
            echo "❌ lcov não encontrado. Execute: ./coverage.sh install"
            exit 1
        fi
        
        # Gera relatório de cobertura
        make coverage
        
        echo ""
        echo "📊 Relatório de cobertura gerado!"
        echo "📁 Localização: $HTML_DIR/index.html"
        echo ""
        echo "Para visualizar o relatório:"
        echo "  ./coverage.sh open"
        echo "  ou"
        echo "  open $HTML_DIR/index.html"
        ;;
    
    "open")
        if [ -f "$HTML_DIR/index.html" ]; then
            echo "🌐 Abrindo relatório de cobertura..."
            open "$HTML_DIR/index.html"
        else
            echo "❌ Relatório não encontrado. Execute primeiro: ./coverage.sh run"
            exit 1
        fi
        ;;
    
    "help"|"-h"|"--help")
        echo "📖 Script de Cobertura de Testes"
        echo ""
        echo "Uso: ./coverage.sh [comando]"
        echo ""
        echo "Comandos disponíveis:"
        echo "  install  - Instala as ferramentas necessárias (lcov)"
        echo "  run      - Executa testes e gera relatório de cobertura"
        echo "  open     - Abre o relatório HTML no navegador"
        echo "  clean    - Remove arquivos de cobertura"
        echo "  help     - Mostra esta ajuda"
        echo ""
        echo "Exemplo de uso:"
        echo "  ./coverage.sh install  # Primeira vez"
        echo "  ./coverage.sh run      # Gerar relatório"
        echo "  ./coverage.sh open     # Visualizar relatório"
        ;;
    
    *)
        echo "❌ Comando desconhecido: $1"
        echo "Execute './coverage.sh help' para ver os comandos disponíveis"
        exit 1
        ;;
esac