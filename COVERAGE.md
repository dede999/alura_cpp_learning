# Sistema de Cobertura de Testes

Este projeto está configurado com um sistema completo de cobertura de testes usando `gcov` e `lcov` para gerar relatórios HTML detalhados.

## Pré-requisitos

- `lcov` instalado no sistema (pode ser instalado automaticamente)
- Compilador GCC/Clang com suporte a gcov

## Instalação das Ferramentas

Para instalar as ferramentas necessárias no macOS:

```bash
./coverage.sh install
```

## Como Usar

### 1. Executar Testes com Cobertura

```bash
# Usando o script (recomendado)
./coverage.sh run

# Ou usando make diretamente
make coverage
```

### 2. Visualizar Relatório

```bash
# Abrir relatório no navegador
./coverage.sh open

# Ou abrir manualmente
open coverage/html/index.html
```

### 3. Limpar Arquivos de Cobertura

```bash
# Usando o script
./coverage.sh clean

# Ou usando make
make clean-coverage
```

## Targets do Makefile

- `test-coverage`: Compila e executa testes com flags de cobertura
- `coverage`: Gera relatório completo de cobertura
- `clean-coverage`: Remove arquivos de cobertura
- `install-coverage-tools`: Instala ferramentas necessárias (macOS)

## Estrutura de Arquivos

```
coverage/
├── coverage.info           # Dados brutos de cobertura
├── coverage_filtered.info  # Dados filtrados
└── html/                   # Relatório HTML
    ├── index.html          # Página principal
    └── ...                 # Arquivos de suporte
```

## Interpretando os Resultados

O relatório HTML mostra:

- **Cobertura de Linhas**: Percentual de linhas executadas
- **Cobertura de Funções**: Percentual de funções chamadas
- **Arquivos por Arquivo**: Detalhamento por arquivo fonte
- **Código Colorido**: 
  - Verde: Linhas executadas
  - Vermelho: Linhas não executadas
  - Cinza: Linhas não instrumentadas

## Exemplo de Uso

```bash
# 1. Instalar ferramentas (primeira vez)
./coverage.sh install

# 2. Executar testes e gerar relatório
./coverage.sh run

# 3. Visualizar resultados
./coverage.sh open

# 4. Limpar quando necessário
./coverage.sh clean
```

## Configurações Especiais para macOS

O sistema está configurado para ignorar warnings específicos do macOS/LLVM:
- Inconsistências de linha
- Formatos não suportados
- Padrões de exclusão não utilizados

## Adicionando Novos Testes

1. Crie arquivos de teste em `test/`
2. Use a estrutura do Catch2
3. Execute `./coverage.sh run` para ver a cobertura atualizada

## Troubleshooting

Se encontrar problemas:

1. Verifique se `lcov` está instalado: `lcov --version`
2. Certifique-se de que os testes compilam: `make test`
3. Limpe arquivos antigos: `./coverage.sh clean`
4. Execute novamente: `./coverage.sh run`