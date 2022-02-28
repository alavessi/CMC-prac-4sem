class Vector
{
public:
    Vector(); // ����������� �� ���������
    Vector(int _size, int _capacity, int* _p);
    Vector(const Vector& v); // ����������� �����������
    ~Vector(); // ����������
    Vector& operator=(const Vector& v); // ���������� ��������� ������������
    void push_back(int a); // �������� ������� a � ����� �������
    int get(int i) const; // ������� i-�� ������� �������
    void set(int i, int value); // ��������� i-��� �������� ������� �������� value
    int get_size() const; // ������� �������� ������ �������
    void print() const; // ������ ����������� ������� �� �����
private:
    int size; // �������� ������ �������
    int capacity; // ������ ���������� ��� ������ ������
    int* p;
};
