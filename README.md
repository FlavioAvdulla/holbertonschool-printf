# holbertonschool-printf

## Përkufizimi i funksionit
```
int _printf(const char *format, ...)
```
Ky funksion merr si vlerë një string me emërtimin "format" dhe një numër të pa caktuar argumentesh.

## Deklarimi i variablave

```
va_list args;
int printed_chars = 0;
const char *p;
```

**va_list args**
(Mban informacionin e nevojshëm për të tërhequr argumentet përkatëse:

`int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);`

**int printed_chars = 0**

Ky int ruan numrin e karaktereve të printuara.

**(const char `*`p)**
Një pointer string me emërtimin "p".

## Inicializimi i `va_list`
```
va_start(args, format)
```
Inicializon **args** për të tërhequr argumentet shtesë pas parametrit **"format"**.

## Iterimi për string-un "format"
```
for (p = format; *p != '\0'; p++)
```
Bëhet e mundur kalimi në të gjitha karakteret e vargut një nga një deri sa të arrihet në fund të tij në `'\0'`.

## Përcaktimi i formatit të Pointer **`*`p**
```
if (*p == '%')
```
Kontrollon nëse karakteri aktual është një `%`, duke treguar fillimin e një specifikuesi të formatit.

```
p++;
```
Bën të mundur kalimin në karakterin tjetër, e cila përcakton tipin e argumentit për tu printuar.

```
switch (*p)
```
Bën të mundur që nëpërmjet tipit të karakterit të percaktoj tipin  e pointerit dhe ë thëras bllokun e kodit përkatës për të realizuar printimin.

## Karakter i tipit char `%c`
```
case 'c':
{
    char c = va_arg(args, int);
    write(1, &c, 1);
    printed_chars++;
    break;
}
```

Ekzekutohet blloku i kodit pasi `switch (*p)` ka përcaktuar tipin e pointer-it bazuar tek karakteri akutal i string (vargut).

`printed_chars++;` kalon në karakterin e radhës.

`break;` Mbaron veprimi.

## Karakter i tipit char * `%s`

```
case 's':
{
    char *str = va_arg(args, char *);
    if (str == NULL)
        str = "(null)";
    while (*str)
    {
        write(1, str, 1);
        str++;
        printed_chars++;
    }
    break;
}
```
Ekzekutohet blloku i kodit pasi `switch (*p)` ka përcaktuar tipin e pointer-it bazuar tek karakteri akutal i string (vargut).

`printed_chars++;`kalon në karakterin e radhës.

`break;` Mbaron veprimi.

## Karakter i tipit int `%d` dhe `%i`
```
case 'd':
case 'i':
{
    int num = va_arg(args, int);
    char buffer[50];
    int len = snprintf(buffer, 50, "%d", num);
    write(1, buffer, len);
    printed_chars += len;
    break;
}
```
Konverton int në string.

`int len = snprintf(buffer, 50, "%d", num);`

Ekzekutohet blloku i kodit pasi `switch (*p)` ka përcaktuar tipin e pointer-it bazuar tek karakteri akutal i string (vargut).

`printed_chars++;`kalon në karakterin e radhës.

`break;` Mbaron veprimi.

## Karakter me tip te pa caktuar.
```
default:
{
    write(1, p, 1);
    printed_chars++;
    break;
}

else
{
    write(1, p, 1);
    printed_chars++;
}
```
Printohet karakteri

`printed_chars++;`kalon në karakterin e radhës.

`break;` Mbaron veprimi.

```
va_end(args);
```
Përcaktohet fundi i `va_list`.

```
return printed_chars;
```
Kthehet numri total i karaktereve të printuara përveç `'\0'`.