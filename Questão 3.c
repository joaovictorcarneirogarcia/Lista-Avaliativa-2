using System;

class Program
{
    // Função para somar matrizes
    static void SomaMatrizes(int[,] A, int[,] B, int[,] resultado)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                resultado[i, j] = A[i, j] + B[i, j];
            }
        }
    }

    // Função para subtrair matrizes
    static void SubtraiMatrizes(int[,] A, int[,] B, int[,] resultado)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                resultado[i, j] = A[i, j] - B[i, j];
            }
        }
    }

    // Função para multiplicar matrizes
    static void MultiplicaMatrizes(int[,] A, int[,] B, int[,] resultado)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                resultado[i, j] = 0;
                for (int k = 0; k < 4; k++)
                {
                    resultado[i, j] += A[i, k] * B[k, j];
                }
            }
        }
    }

    static void Main()
    {
        int[,] matrizA = new int[4, 4];
        int[,] matrizB = new int[4, 4];
        int[,] resultado = new int
