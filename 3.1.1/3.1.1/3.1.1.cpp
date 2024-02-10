#include <iostream>

class SmartArray {
public:
   SmartArray(int size) {
      this->size = size;
      this->arr = new int[size];
      std::cout << "constructor" << std::endl;
   }
   ~SmartArray() {
      delete[] arr;
      std::cout << "destructor" << std::endl;
   }

   SmartArray(const SmartArray&) = delete;
   SmartArray& operator=(const SmartArray&) = delete;

   void addElement(int value) {
      if (index < size) {
         arr[index] = value;
         index++;
      }
      else {
         throw std::runtime_error("Index out of bounds");
      }
   }

   int getElement(int index) {
      if (index < 0 || index > this->index - 1) {
         throw std::runtime_error("Index out of bounds");
      }
      else {
         return arr[index];
      }
   }


private:
   int* arr;
   int size;
   int index = 0;
};

int main() {

   try {
      SmartArray arr(5);
      arr.addElement(1);
      arr.addElement(2);
      arr.addElement(3);
      arr.getElement(3); // Для проверки вызываю элемент не заполненный элемент в рамках массива. Вызывается исключение

      SmartArray newArr(5);
      newArr.addElement(1);
      newArr.addElement(2);
      newArr.addElement(3);

   }
   catch (const std::exception& ex) {
      std::cout << ex.what() << std::endl;
   }
}