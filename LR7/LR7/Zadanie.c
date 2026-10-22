#include <stdio.h>
#include <locale.h>
#include <math.h>

void z_1(char c);
void z_2(float x, char c, float y);
void z_3(int degree);

int main() {

	setlocale(LC_CTYPE, "ru_RU.UTF-8");

	printf("Задание 1\n");
	char c; 
	printf("Введите символ: ");
	scanf("%c", &c);

	z_1(c);

	printf("\nЗадание 2\n");
	float x, y;

	printf("Введите выражение (например, 5.5+2 или 3^4): ");
	scanf(" %f%c%f", &x, &c, &y);

	z_2(x, c, y);

	printf("\nЗадание 3\n");
	int degree;
	printf("Введите показатель степени числа 10 (например, -12, -9, 3, 12): ");
	scanf("%d", &degree);

	z_3(degree);

	return 0;
}

void z_1(char c)
{
	switch (c)
	{
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			printf("Это цифра\n");
			break;

		default:
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
				printf("Это буква\n");
			}
			else {
				printf("Это другой символ\n");
			}
			break;
	}
}

void z_2(float x, char c, float y)
{
	switch (c)
	{
		case '+':
			printf("Результат: %f\n", x + y);
			break;

		case '-':
			printf("Результат: %f\n", x - y);
			break;

		case '*':
			printf("Результат: %f\n", x * y);
			break;

		case '/':
			if (y == 0.0f) {
				printf("Ошибка: Деление на ноль невозможно!\n");
			}
			else {
				printf("Результат: %f\n", x / y);
			}
			break;

		case '^':
			printf("Результат: %f\n", pow(x, y));
			break;

		default:
			printf("Ошибка: Неизвестная операция '%c'!\n", c);
			break;
	}
}
void z_3(int degree)
{
	switch (degree)
	{
		case -12:
			printf("10^-12 - пико...\n");
			break;

		case -9:
			printf("10^-9 - нано...\n");
			break;

		case -6:
			printf("10^-6 - микро...\n");
			break;

		case -3:
			printf("10^-3 - милли...\n");
			break;

		case 0:
			printf("10^0 - единица\n");
			break;

		case 3:
			printf("10^3 - кило...\n");
			break;

		case 6:
			printf("10^6 - мега...\n");
			break;

		case 9:
			printf("10^9 - гига...\n");
			break;

		case 12:
			printf("10^12 - тера...\n");
			break;

		default:
			printf("Для степени 10^%d нет стандартной приставки в диапазоне от пико до тера\n", degree);
			break;
	}
}
