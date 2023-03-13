#include <iostream>

class bitvector {
	public:
		bitvector(const int N)
	       :real_size(N)	{
		       arr_size = N / (sizeof(long) * 8);
		       if(N % (sizeof(unsigned long) * 8)){
		       		arr_size++;
		       }
	       		arr = new unsigned long[arr_size]();
			//std::cout << arr_size;

	       }
		void set(const int N){
			if(!valid(N)) {
				return;	
			}
			int i = N / (sizeof(long) * 8);
			int j = N % (sizeof(long) * 8);
			//std::cout << i << " " << j;
			arr[i] = arr[i] | (1 << j);
		}
		void reset(const int N){
			if(!valid(N)){
				return;
			}
			int i = N / (sizeof(long) * 8);
			int j = N % (sizeof(long) * 8);
			//std::cout << i << " " << j;
			arr[i] = arr[i] & ~(1 << j);
		}
		void print() {
			std::cout << "Prints indexes from right to left\n";
			for(int i = arr_size - 1; i >= 0; i--) {
				std::cout << arr[i] << " ";
		}
			return;
		}
		~bitvector() {
			delete[] arr;
		}
	private:
		unsigned int real_size;
		unsigned int arr_size;
		unsigned long*arr;
		bool valid(const int N) {
			if(N >= 0 && N < real_size){
				return true;
			}
			return false;
		};
};

int main() {
	int len;
	std::cin >> len;
	bitvector b(len);
	std::cout << "Note that you can set or reset only in the range of 0 to " << len - 1 << "\n";
	b.set(5);
	b.print();
	return 0;
}
