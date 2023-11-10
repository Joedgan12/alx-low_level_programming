#include "3-calc.h"
#include <stdlib.h>

/**
 * get_op_func - selects the correct function to perform
 * the operation asked by user
 * @s: operator passed as argument
 * return: pointerto the function corresponding
 * to the operator given as parameter
 */
int (*get_op_func(char *s))(int, int)
{
	op_t op[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (op[i].op != NULL && *(op[i].op) != *s)
		i++;

	return (op[i].f);
}
