COUNTER_FILE := lecture_num.txt

N := $(shell if [ -f $(COUNTER_FILE) ]; then cat $(COUNTER_FILE); else echo 1; fi)

SRC_DIR := src
BIN_DIR := bin

SRC_FILE := $(SRC_DIR)/lecture$(N).cpp
TARGET   := $(BIN_DIR)/lecture$(N)

ED		 := micro
CXX      := g++
CXXFLAGS := -Wall -Wextra -std=c++17

.PHONY: all next clean

all: $(TARGET)
	@echo "Debugging..."
	@./$(TARGET)
	@echo "Done!"

$(TARGET): $(SRC_FILE)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(SRC_FILE) -o $(TARGET)

edit:
	@$(ED) $(SRC_FILE)

next:
	$(eval NEXT_N := $(shell echo $$(($(N) + 1))))
	@echo $(NEXT_N) > $(COUNTER_FILE)
	@echo "Текущий номер лекции изменен на: $(NEXT_N)"
	@mkdir -p $(SRC_DIR)
	
	@if [ ! -f $(SRC_DIR)/lecture$(NEXT_N).cpp ]; then \
		echo '#include <iostream>' > $(SRC_DIR)/lecture$(NEXT_N).cpp; \
		echo '' >> $(SRC_DIR)/lecture$(NEXT_N).cpp; \
		echo 'int main() {' >> $(SRC_DIR)/lecture$(NEXT_N).cpp; \
		echo '    std::cout << "Hello from Lecture '$(NEXT_N)'!" << std::endl;' >> $(SRC_DIR)/lecture$(NEXT_N).cpp; \
		echo '    return 0;' >> $(SRC_DIR)/lecture$(NEXT_N).cpp; \
		echo '}' >> $(SRC_DIR)/lecture$(NEXT_N).cpp; \
		echo "Создан новый файл: $(SRC_DIR)/lecture$(NEXT_N).cpp"; \
	else \
		echo "Файл $(SRC_DIR)/lecture$(NEXT_N).cpp уже существует."; \
	fi

clean:
	rm -f $(BIN_DIR)/lecture[0-9]*
	@echo "Скомпилированные файлы удалены."
