#include <iostream>
#include <stdexcept>

template <typename T>
class myVector {
private:
	T* array;
	int elements, count;
public:
	myVector(int number){
		elements = number;
		count = 0;
		array = new T[elements];
	}

	~myVector() {
		delete[] array;
	}

	T at(int index) {
		if (index >= count) {
			throw std::invalid_argument("invalid array index");
		}
		else {
			return array[index];
		}
	}

	void push_back(T value) {
		if (count > (elements - 1)) {
			T* temp = new T[elements * 2];
			for (size_t i = 0; i <= count; i++) {
				temp[i] = array[i];
			}
			temp[count + 1] = value;
			elements *= 2;

			delete[] array;
			array = new T[elements];

			for (size_t i = 0; i <= (count + 1); i++) {
				array[i] = temp[i];
			}

			delete[] temp;
		}
		else {
			array[count] = value;
		}
		count++;
	}

	int size() {
		return count;
	}

	int capacity() {
		return (elements - 1 - count);
	}
};

int main() {
	myVector<int> vector(5);

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);
	vector.push_back(6);

	std::cout << vector.size() << std::endl;

	std::cout << vector.capacity() << std::endl;

	std::cout << vector.at(4) << std::endl;

//	std::cout << vector.at(50) << std::endl; //для проверки, что вектор выбрасывает исключение при неверном индексе

}