# Projet Rencontres Étudiants-Entreprises (REE)

## Exécutione

g++ -std=c++11 -o programme main.cpp Entreprise.cpp Etudiant.cpp RendezVous.cpp ExperiencePro.cpp InscriptionActuelle.cpp Date.cpp Heure.cpp Diplome.cpp GestionEtudiant.cpp GestionEntreprise.cpp DoubleDiplome.cpp EtudiantDeuxiemeCycle.cpp EtudiantPremierCycle.cpp

Vérifier la présence de g++ et des librairies.


## RAPPEL PROJET

## Objectif du projet

Ce projet consiste à réaliser un logiciel de gestion des Rencontres Étudiants-Entreprises (REE) depuis la phase d'analyse jusqu'à l'implémentation en C++. Le but est de permettre la gestion d'étudiants et d'entreprises participantes à ces rencontres, avec diverses fonctionnalités pour ajouter et gérer les informations des étudiants, des entreprises et des rendez-vous.

## Fonctionnalités du logiciel

Le logiciel doit assurer les fonctionnalités suivantes :

### 1. Gestion des Étudiants
Les étudiants sont classés en deux catégories :
- **Étudiants de premier cycle** (Licence, IUT, etc.)
  - Informations : Numéro d'étudiant, nom, prénom, adresse, numéro de téléphone, série du Bac, année et lieu d'obtention.
- **Étudiants de deuxième cycle** (Masters, École d’ingénieur, etc.)
  - Informations : Nom de la discipline principale (Informatique, Mathématiques, etc.)

De plus, pour chaque étudiant, le logiciel doit gérer :
- Diplômes obtenus (code, nom, lieu, date d’obtention).
- Inscription actuelle (date d'inscription et année d'inscription).
- Expériences professionnelles (date de début et de fin, entreprise et fonction occupée).

### 2. Gestion des Entreprises
Le logiciel doit gérer les informations des entreprises participant aux journées REE :
- Nom de l’entreprise.
- Adresse de l’entreprise.
- Nom et téléphone du contact dans l'entreprise.

### 3. Gestion des Rendez-vous
Le logiciel permet de gérer les rendez-vous entre étudiants et entreprises :
- Date et heures des rendez-vous.
- Le logiciel doit garantir qu'il n'y a pas de conflit dans les horaires (pas plusieurs rendez-vous dans la même tranche horaire pour un étudiant ou une entreprise).

### 4. Fonctionnalités de saisie
- Ajout des informations (étudiant, entreprise, rendez-vous).
- Vérification lors de la saisie pour éviter les doublons.
- Vérification de la compatibilité des horaires des rendez-vous.

### 5. Fonctionnalités d'édition
- Liste triée des rendez-vous pour chaque étudiant (par nom, prénom et numéro d'étudiant).
- Liste triée des rendez-vous pour chaque entreprise (par nom et date).
- Génération du CV d'un étudiant (informations administratives, diplômes obtenus, expériences professionnelles).

## Technologies utilisées

- **Langage de programmation** : C++
- **Analyse** : Diagrammes UML pour représenter la structure du logiciel et les relations entre les entités.
