#include <stdio.h>
#include <locale.h>
#include <math.h>

int z_1(char c);
float z_2(float x, char c, float y);
int z_3(int degree);

int main() {
	setlocale(LC_CTYPE, "ru_RU.UTF-8");

	//Задание 1
	printf("Задание 1\n");

	char c;

	printf("Введите символ: ");
	scanf("%c", &c);

	int char_type = z_1(c);

	if (char_type == 1) 
		printf("Это цифра\n");

	else if (char_type == 2) 
		printf("Это буква\n");

	else 
		printf("Это другой символ\n");


	//Задание 2
	printf("\nЗадание 2\n");

	float x, y;

	printf("Введите выражение (например, 5.5+2 или 3^4): ");
	scanf(" %f%c%f", &x, &c, &y);

	if (c != '+' && c != '-' && c != '*' && c != '/' && c != '^') {
		printf("Ошибка: Неизвестная операция '%c'!\n", c);
	}
	else if (c == '/' && y == 0.0f) {
		printf("Ошибка: Деление на ноль невозможно!\n");
	}
	else {
		float calc_result = z_2(x, c, y);
		printf("Результат: %f\n", calc_result);
	}


	//Задание 3
	printf("\nЗадание 3\n");
	int degree;
	printf("Введите показатель степени числа 10 (например, -12, -9, 3, 12): ");
	scanf("%d", &degree);

	int code = z_3(degree);

	switch (code) {
		case 1:  printf("10^%d - пико...\n", degree); break;
		case 2:  printf("10^%d - нано...\n", degree); break;
		case 3:  printf("10^%d - микро...\n", degree); break;
		case 4:  printf("10^%d - милли...\n", degree); break;
		case 5:  printf("10^0 - единица\n"); break;
		case 6:  printf("10^%d - кило...\n", degree); break;
		case 7:  printf("10^%d - мега...\n", degree); break;
		case 8:  printf("10^%d - гига...\n", degree); break;
		case 9:  printf("10^%d - тера...\n", degree); break;
		default: printf("Для степени 10^%d нет стандартной приставки в диапазоне от пико до тера\n", degree); 
		break;
	}

	return 0;
}

int z_1(char c) {
	switch (c) {
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		return 1;
	default:
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
			return 2;
		else return 3;
	}
}

float z_2(float x, char c, float y) {
	switch (c) {
		case '+': return x + y;
		case '-': return x - y;
		case '*': return x * y;
		case '/': return x / y;
		case '^': return pow(x, y);
		default: return 0.0f;
	}
}

int z_3(int degree) {
	switch (degree) {
		case -12: return 1;
		case -9: return 2;
		case -6: return 3;
		case -3: return 4;
		case 0: return 5;
		case 3: return 6;
		case 6: return 7;
		case 9: return 8;
		case 12: return 9;
		default: return 0;
	}
}
