#ifndef __VECTOR_ARRAY_IFRN__
#define __VECTOR_ARRAY_IFRN__
class vector_array {
private:
    int *data;
    unsigned int size_, capacity_;
    void increase_capacity() {        
        int new_capacity = this->capacity_ * 2;
        int *new_data = new int[new_capacity];
        for (unsigned int i = 0; i < this->size_; i++) {
            new_data[i] = data[i];
        }
        delete [] this->data;
        this->data = new_data;
        this->capacity_ = new_capacity;
    }

public:
    vector_array() {         // Construtor
        data = new int[8];
        this->size_ = 0;
        this->capacity_ = 8;
    }
    ~vector_array() { // Destrutor
        delete [] data;
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return this->size_;
    }
    unsigned int capacity() { // Retorna o espaço reservado para armazenar os elementos
        return this->capacity_;
    }
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0 com o percentual da memória usada
        return static_cast<double>(this->size_)/this->capacity_;
    }
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
        if (index > this->size_) { 
            return false;
        }
        if (this->size_ == this->capacity_) {
            increase_capacity();
        }
        for (unsigned int i = this->size_; i > index; i--) {
            this->data[i] = this->data[i - 1];
        }
        this->data[index] = value;
        this->size_++;
        return true;
    }
    bool remove_at(unsigned int index) { // Remove elemento do índice index
        if (index >= this->size_) {
            return false;
        }
        for (unsigned int i = index; i < this->size_-1; i++) {
            this->data[i] = this->data[i + 1];
        }
        this->size_--;
        return true;
    }
    bool is_empty() { // Retorna true se o vetor não contém elementos
        return this->size_ == 0;
    }
    int get_at(unsigned int index) { // Retorna elemento no índice index
        if (index >= this->size_) {
            return -1;              // −1 se índice inválido
        }
        return this->data[index];
    }
    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        delete [] data;
        data = new int[8];
        this->size_ = 0;
        this->capacity_ = 8;
    }
    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
        if (this->size() == this->capacity()) {
            increase_capacity();
        }
        this->data[this->size_] = value;
        this->size_++;
    }
    void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
        if (this->size() == this->capacity()) {
            increase_capacity();
        }
        int *new_data = new int[this->capacity_];
        new_data[0] = value;
        for (unsigned int i = 0; i < this->size_; i++) {
            new_data[i+1] = data[i];
        }
        delete [] this->data;
        this->data = new_data;
        this->size_++;
    }
    bool pop_back() {            // Remove um elemento do ``final'' do vetor
        if (this->size_ == 0) {
            return false;
        }
        this->size_--;
        return true;
    }
    bool pop_front() {           // Remove um elemento do ``início'' do vetor
        if (this->size_ == 0) {
            return false;
        }
        for (unsigned int i = 0; i < this->size_ - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        this->size_--;
        return true;
    }
    int back() {                 // Retorna o elemento do ``final'' do vetor
        if (this->size_ == 0) {
            return -1;
        }
        return this->data[this->size_ - 1];
    }
    int front() {                // Retorna o elemento do ``início'' do vetor
        if (this->size_ == 0) {
            return -1;
        }
        return this->data[0];
    }
    bool remove(int value) {     // Remove value do vetor caso esteja presente
        for (unsigned int i = 0; i < this->size_; i++) {
            if (this->data[i] == value) {
                remove_at(i);
                return true;
            }
        }
        return false;
    }
    int find(int value) {        // Retorna o índice de value, −1 caso value não esteja presente
        for (unsigned int i = 0; i < this->size_; i++) {
            if (this->data[i] == value) {
                return i;
            }
        }
        return -1;
    }
    int count(int value) {       // Retorna quantas vezes value occorre no vetor
        int somador = 0;
        for (unsigned int i=0; i < this->size_; i++) {
            if (this->data[i] == value) {
                somador++;
            }
        }
        return somador;                // Retorna 0 se value não estiver presente
    }
    int sum() {                  // Retorna a soma dos elementos do vetor
        int somador = 0;
        for (unsigned int i=0; i < this->size_; i++) {
            somador += this->data[i];
        }
        return somador;                // Retorna 0 se o vetor estiver vazio
    }
};
#endif // __VECTOR_LIST_IFRN__