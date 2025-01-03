# Nom de l'exécutable
TARGET = main

# Répertoire source
SRCDIR = src

# Fichiers sources dans le dossier src
SRCS = $(SRCDIR)/main.cpp $(SRCDIR)/Entreprise.cpp $(SRCDIR)/Heure.cpp $(SRCDIR)/RendezVous.cpp $(SRCDIR)/Etudiant.cpp $(SRCDIR)/Date.cpp $(SRCDIR)/EtudiantPremierCycle.cpp $(SRCDIR)/EtudiantDeuxiemeCycle.cpp $(SRCDIR)/InscriptionActuelle.cpp $(SRCDIR)/Diplome.cpp $(SRCDIR)/ExperiencePro.cpp

# Options de compilation
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Règle par défaut : construire l'exécutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Nettoyage des fichiers générés
clean:
	rm -f $(TARGET)
