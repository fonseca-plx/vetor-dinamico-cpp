#ifndef __VECTOR_LINKED_IFRN__
#define __VECTOR_LINKED_IFRN__
class vector_linked {
private:
    struct int_node {
        int value;
        int_node *next, *prev;
    };
    int_node *head, *tail;
    unsigned int size_;

public:
    vector_linked() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }
    ~vector_linked() {
        int_node *current = this->head;
        while (current != nullptr) {
            int_node *to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return 0;
    }
    unsigned int capacity() { // Retorna o espaço
        return 0;
    } // reservado para armazenar os elementos
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0
        return 0;               // com o percentual da memória usada.
    }
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
        return false;
    }
    bool remove_at(unsigned int index) { // Remove elemento do índice index
        return false;
    }
    bool is_empty() { // Retorna true se o vetor não contém elementos
        return false;
    }
    int get_at(unsigned int index) { // Retorna elemento no índice index,
        return -1;                   // −1 se índice inválido
    }
    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
    }
    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
        int_node *new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = this->tail;
        if (this->head == nullptr) {
            this->head = new_node;
        }
        else {
            this->tail->next = new_node;
        }
        this->tail = new_node;
    }
    void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
        int_node *new_node = new int_node;
        new_node->value = value;
        new_node->next = this->head;
        new_node->prev = nullptr;
        if (this->head == nullptr) {
            this->tail = new_node;
        }
        else {
            this->head->prev = new_node;
        }
        this->head = new_node;
    }
    bool pop_back() { // Remove um elemento do ``final'' do vetor
        if (this->tail == nullptr) {
            return false;
        }
        if (this->head == this->tail) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            return true;
        }
        this->tail = this->tail->prev;
        delete this->tail->next;
        this->tail->next = nullptr;
        return true;
    }
    bool pop_front() { // Remove um elemento do ``início'' do vetor
        if (this->head == nullptr) {
            return false;
        }
        if (this->head == this->tail) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            return true;
        }
        this->head = this->head->next;
        delete this->head->prev;
        this->head->prev = nullptr;
        return true;
    }
    int back() { // Retorna o elemento do ``final'' do vetor
        if (this->size() == 0) {
            return -1;
        }
        return this->tail->value;
    }
    int front() { // Retorna o elemento do ``início'' do vetor
        if (this->size() == 0) {
            return -1;
        }
        return this->head->value;
    }
    bool remove(int value) { // Remove value do vetor caso esteja presente
        return false;
    }
    int find(int value) { // Retorna o índice de value, −1 caso value não esteja presente
        return -1;
    }
    int count(int value) { // Retorna quantas vezes value occorre no vetor
        return 0;
    }
    int sum() { // Retorna a soma dos elementos do vetor
        return 0;
    }
};
#endif // __VECTOR_LINKED_IFRN__