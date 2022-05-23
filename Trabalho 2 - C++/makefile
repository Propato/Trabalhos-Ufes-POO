############
# Exemplo de makefile
# Prof. João Paulo A. Almeida
# Programação III
# 
#
# Modificado por Carlos Daniel Albertino Vieira e David Cristian Motta Propato.

# nome do compilador
CPP = g++

# opções de compilação
CFLAGS = -Wall -g
CPPFLAGS = -std=c++11

# define lista de arquivos-fonte, assumindo que estão no diretório atual
FONTES = $(wildcard ./src/candidatos/*.cpp) $(wildcard ./src/partidos/*.cpp) $(wildcard ./src/leitura/*.cpp) $(wildcard ./src/comum/*.cpp) $(wildcard ./src/*.cpp)

# define lista de bibliotecas, assumindo que estão no diretório atual
LIBS = $(wildcard ./lib/candidatos/*.h) $(wildcard ./lib/partidos/*.h) $(wildcard ./lib/leitura/*.h) $(wildcard ./lib/comum/*.h) $(wildcard ./lib/*.h)

# define lista dos arquivos-objeto usando nomes da lista de arquivos-fonte
OBJETOS = $(subst src,obj,$(FONTES:.cpp=.o))

# nome do arquivo executável
EXECUTAVEL = vereadores
CIDADE = cariacica

# folder contendo objetos
OBJ_FOLDER = ./obj ./obj/candidatos ./obj/comum ./obj/leitura ./obj/partidos

############ alvos
#
# use @ antes de todos os comandos, pois é necessário no script de teste
#

# alvo principal é o executável  
all: $(OBJ_FOLDER) $(EXECUTAVEL)

$(OBJ_FOLDER):
	@mkdir -p $@

# para linkar o executável, precisamos dos arquivos-objetos
$(EXECUTAVEL): $(OBJETOS)
	@$(CPP) -o $@ $^ 

# alvo para cada arquivo-objeto depende do código fonte
obj/%.o: src/%.cpp $(LIBS)
	@$(CPP) $(CPPFLAGS) -c $(CFLAGS) $< -o $@

# o comando para executar deve especificar sempre como parâmetro divulga.csv	
run: $(EXECUTAVEL)
	@./$(EXECUTAVEL) candidatos.csv partidos.csv 15/11/2020

# comando para limpeza
clean: 
	@rm -rf $(OBJETOS) $(EXECUTAVEL)
	rmdir obj/candidatos obj/comum obj/leitura obj/partidos obj

echo:
	@echo -e '$(FONTES)\n$(LIBS)\n$(OBJETOS)\n$(OBJ_FOLDER)'

val: $(EXECUTAVEL)
	@valgrind -s --leak-check=full ./$(EXECUTAVEL) candidatos.csv partidos.csv 15/11/2020