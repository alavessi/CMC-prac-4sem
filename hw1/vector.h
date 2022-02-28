class Vector
{
public:
    Vector(); // конструктор по умолчанию
    Vector(int _size, int _capacity, int* _p);
    Vector(const Vector& v); // конструктор копирования
    ~Vector(); // деструктор
    Vector& operator=(const Vector& v); // перегрузка оператора присваивания
    void push_back(int a); // добавить элемент a в конец вектора
    int get(int i) const; // вернуть i-ый элемент вектора
    void set(int i, int value); // присвоить i-ому элементу вектора значение value
    int get_size() const; // вернуть реальный размер вектора
    void print() const; // печать содержимого вектора на экран
private:
    int size; // реальный размер вектора
    int capacity; // размер выделенной под вектор памяти
    int* p;
};
