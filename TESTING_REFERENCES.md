# Referências para Técnicas Avançadas de Testing em C++

Este documento contém referências e recursos para aprender mais sobre técnicas avançadas de testing em C++, especialmente para testar funções `void` e captura de output.

## 🎯 Técnicas Principais Abordadas

### 1. Stream Redirection (Redirecionamento de Streams)
- Captura de output de `std::cout` usando `std::stringstream`
- Manipulação de `std::streambuf`
- Técnica RAII para gerenciamento automático de recursos

### 2. OutputCapture Pattern
- Classe helper para capturar output de console
- Redirecionamento temporário e restauração automática
- Testabilidade de funções `void` que fazem print

## 📚 Recursos para Estudo

### 🎓 Livros Recomendados

#### Técnicas de C++
- **"Effective C++" - Scott Meyers**
  - Técnicas avançadas de C++
  - RAII e gerenciamento de recursos
  - Padrões de design fundamentais

- **"Modern C++ Design" - Andrei Alexandrescu**
  - Técnicas avançadas de template
  - Padrões de design modernos
  - Meta-programação

- **"C++ Concurrency in Action" - Anthony Williams**
  - Programação concorrente
  - Técnicas avançadas de sincronização

#### Testing e Qualidade de Código
- **"The Art of Unit Testing" - Roy Osherove**
  - Técnicas de teste unitário
  - Padrões para testar código difícil
  - Mocking e stubbing

- **"Working Effectively with Legacy Code" - Michael Feathers**
  - Técnicas para testar código existente
  - Refatoração para testabilidade
  - Quebra de dependências

- **"Clean Code" - Robert C. Martin**
  - Princípios de código limpo
  - Testabilidade e design
  - Boas práticas de desenvolvimento

### 🌐 Recursos Online

#### Documentação Oficial
- **[cppreference.com](https://cppreference.com)**
  - Documentação oficial sobre streams
  - Exemplos de `std::streambuf`
  - Referência completa de iostream

- **[ISO C++ Guidelines](https://isocpp.github.io/CppCoreGuidelines/)**
  - Diretrizes oficiais do C++
  - Boas práticas de testing
  - Padrões recomendados

#### Comunidades e Fóruns
- **[Stack Overflow](https://stackoverflow.com)**
  - Busque por: "c++ redirect cout to string"
  - "c++ stream buffer manipulation"
  - "unit testing cout output"

- **[Reddit r/cpp](https://reddit.com/r/cpp)**
  - Discussões sobre técnicas avançadas
  - Perguntas e respostas da comunidade

#### Frameworks de Testing
- **[Google Test Documentation](https://google.github.io/googletest/)**
  - Técnicas avançadas de testing
  - Mocking frameworks
  - Output capture patterns

- **[Catch2 Documentation](https://github.com/catchorg/Catch2)**
  - Framework que estamos usando
  - Exemplos avançados
  - Técnicas de assertion

### 🎥 Conteúdo em Vídeo

#### YouTube Channels
- **CppCon**
  - Palestras sobre testing avançado
  - "Back to Basics" series
  - Técnicas de debugging

- **Meeting C++**
  - Conferências sobre C++ moderno
  - Técnicas avançadas

#### Cursos Online
- **Coursera/edX**
  - Cursos avançados de C++
  - Software Testing courses
  - Computer Science fundamentals

## 🔍 Termos para Pesquisar

### Stream Manipulation
- "C++ stream redirection"
- "std::streambuf manipulation"
- "iostream internals C++"
- "stream buffer swapping C++"


### Testing Patterns
- "Unit testing console output"
- "Testing void functions C++"
- "C++ output capture techniques"
- "RAII testing patterns"

### Design Patterns
- "C++ RAII pattern"
- "Dependency injection C++"
- "Mock objects C++"
- "Test doubles C++"


## 🛠️ Frameworks e Ferramentas

### Testing Frameworks
1. **Google Test/Google Mock**
   - Framework de teste mais popular
   - Técnicas avançadas de mocking
   - Integração com CI/CD

2. **Catch2** ⭐ (Atual)
   - Framework que estamos usando
   - Sintaxe limpa e expressiva
   - Header-only library

3. **Boost.Test**
   - Framework robusto da Boost
   - Muitas funcionalidades avançadas
   - Integração com Boost ecosystem

### Coverage Tools
1. **gcov/lcov** ⭐ (Atual)
   - Ferramenta padrão do GCC
   - Relatórios HTML detalhados
   - Integração com CI/CD

2. **Codecov**
   - Serviço online de coverage
   - Integração com GitHub
   - Análise de trends

## 💡 Técnicas Avançadas para Explorar

### 1. Dependency Injection
```cpp
void print_message(const std::string& msg, std::ostream& out = std::cout) {
    out << msg << std::endl;
}

// Teste:
std::stringstream test_stream;
print_message("test", test_stream);
REQUIRE(test_stream.str() == "test\n");
```

### 2. Template-based Output
```cpp
template<typename Stream>
void print_to_stream(Stream& stream, const std::string& msg) {
    stream << msg << std::endl;
}
```

### 3. Mock Objects
```cpp
class MockOutputStream {
public:
    MOCK_METHOD(void, write, (const std::string&));
};
```

### 4. Fixture Classes
```cpp
class OutputCaptureFixture {
protected:
    OutputCapture capture;
    
    void SetUp() {
        // Setup automático
    }
    
    void TearDown() {
        // Cleanup automático
    }
};
```

## 🎯 Próximos Passos Sugeridos

### Nível Iniciante
1. **Experimente variações da técnica OutputCapture:**
   - Capture de `std::cerr`
   - Redirecionamento de input (`std::cin`)
   - Múltiplos streams simultaneamente

2. **Estude padrões RAII:**
   - Smart pointers
   - Lock guards
   - Resource management

### Nível Intermediário
1. **Explore padrões de design:**
   - Observer pattern
   - Strategy pattern
   - Factory pattern

2. **Testing avançado:**
   - Property-based testing
   - Parametrized tests
   - Test fixtures

### Nível Avançado
1. **Técnicas de mocking:**
   - Interface segregation
   - Dependency inversion
   - Test doubles

2. **Performance testing:**
   - Benchmarking
   - Profiling
   - Memory leak detection

## 📖 Exemplos Práticos

### OutputCapture Básico
```cpp
TEST_CASE("Testing console output") {
    OutputCapture capture;
    
    std::cout << "Hello World" << std::endl;
    
    REQUIRE(capture.getOutput() == "Hello World\n");
}
```

### Testing com Setup/Teardown
```cpp
class GameTestFixture {
protected:
    OutputCapture capture;
    std::vector<display> test_display;
    
    void SetUp() {
        test_display.push_back({'H', true});
        test_display.push_back({'I', false});
    }
};
```

### Parametrized Testing
```cpp
TEST_CASE("ASCII limbs", "[parametrized]") {
    for (int limbs = 0; limbs <= 6; limbs++) {
        OutputCapture capture;
        draw_ascii_limbs(limbs);
        
        std::string output = capture.getOutput();
        REQUIRE_FALSE(output.empty());
        REQUIRE(output.find("+---+") != std::string::npos);
    }
}
```

## 🔗 Links Úteis

- [C++ Testing Best Practices](https://github.com/cpp-best-practices/cppbestpractices)
- [Modern C++ Testing](https://github.com/onqtam/doctest)
- [C++ Core Guidelines - Testing](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-testing)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

## 📝 Notas

- A técnica OutputCapture é um exemplo perfeito de RAII
- Stream redirection é uma técnica fundamental em C++
- Testing de funções void requer criatividade e técnicas especiais
- A combinação de RAII + Stream manipulation é muito poderosa

## 🔧 Implementação no Projeto Atual

### Nossa Classe OutputCapture
Localizada em: `test/utils/output_capture.hpp` e `test/utils/output_capture.cpp`

```cpp
// Membros principais:
std::stringstream buffer;      // Buffer para capturar output
std::streambuf* old_cout;     // Backup do cout original

// Uso no construtor:
old_cout = std::cout.rdbuf();  // Salva cout original
std::cout.rdbuf(buffer.rdbuf()); // Redireciona para buffer

// Restauração no destructor:
std::cout.rdbuf(old_cout);     // Restaura cout original
```

### Exemplo de Uso no Projeto
```cpp
TEST_CASE("Testing show_display function") {
    OutputCapture capture;
    std::vector<display> test_display = {{'H', true}, {'I', false}};
    
    show_display(test_display);
    
    std::string output = capture.getOutput();
    REQUIRE(output.find("H") != std::string::npos);
    REQUIRE(output.find("_") != std::string::npos);
}
```

---

**Projeto:** Alura C++ - Sistema de Testing Avançado  
**Técnica Principal:** OutputCapture para testing de funções void  
**Status:** Implementado e funcional ✅