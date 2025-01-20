# Dannyel Fontenele Ribeiro – 2322130061

- 1

  se p = 0x200, p + 10 dará:
  
  - 0x214, se (short int *)
  - 0x228, se (int *)
  - 0x20a, se (char *)

---

- 2

```
#include <stdio.h>

int main() {
  int rgba = 0X010203FF;
  unsigned char *c = (unsigned char *) &rgba;
  
  char *canais[] = {"Alfa", "B", "G", "R"};
  for (int i = 3; i >= 0; i--)
    printf("%s: %02X (%d em decimal)\n", canais[i], *(c + i), *(c + i));
  return 0;
}
```

---
---

- 1

  ```
  char s[] = "Maria", *ptr = s;
  /*'M' @ addr 1000, 1000 @ addr 5000*/
  ```
   
  | Usando s | Usando ptr | Valor |
  | -------- | ---------- | ----- |
  |   s[2]   | *(ptr + 2) |   r   |
  | s[4000]  |*(ptr + 4000)| 1000 |
  |  s + 1   |  ptr + 1   | 1001  |
  | s + 4000 | ptr + 4000 | 5000  |

---

- 2
  ```
  int v[6] = {4, 3, 7, 5, 6, 2};
  int *pv;
  pv = &v;
  /*4 @ addr 200, 200 @ addr 300*/
  ```
  - _O endereço de memória onde se encontra o elemento 5 do vetor v é 203._ **F**
  - _O endereço de memória onde se encontra o elemento 2 do vetor v é 220._ **V**
  - _Para acessar o elemento 5 do vetor v com notação de ponteiros, basta declarar pv + 3._ **V**
  - _v e pv podem acessar os elementos do vetor utilizando a mesma notação, seja esta notação tanto de vetor quanto a de ponteiro._ **F**
  - _Para acessar o endereço de memória do elemento 7, basta declarar tanto &v[2] quanto *(pv + 2)._ **F**
  - _Após executar a instrução *(pv + 3) = 7, o valor de v[3] é alterado de 5 para 7._ **V**