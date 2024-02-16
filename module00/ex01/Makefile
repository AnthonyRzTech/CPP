TARGET = MyAwesomePhoneBook

# Compilateur à utiliser
CC = g++

# Flags de compilation
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Fichiers source
SOURCES = Contact.cpp PhoneBook.cpp main.cpp

# Règle pour construire le target
all: $(TARGET)

# Règle pour lier les fichiers objets en un exécutable
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Commande pour nettoyer les fichiers compilés
clean:
	rm -f $(TARGET)
