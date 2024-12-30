# Définition du compilateur et des options
CXX = g++
CXXFLAGS = -std=c++11

# Nom de l'exécutable
EXE = main

# Fichiers source
SRC = main.cpp Diplome.cpp DoubleDiplome.cpp

# Règle par défaut pour construire l'exécutable
all: $(EXE)

# Lier tous les fichiers source pour créer un seul exécutable
$(EXE): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXE)

# Commande pour nettoyer l'exécutable
clean:
	rm -f $(EXE)
