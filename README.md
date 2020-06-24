# SDP-1
Нека е дадена следната дефиниция на израз:

израз = неотрицателно цяло число | f(израз) | g(израз) | m(израз,израз), където:

● f(x) = (x * x) mod 100, където mod 100 връща остатъка при деление на 100

● g(x) = (x mod 5) ! , т.е. факториелът на остатъка на деленето на х на 5

● m(x,y) = min(x,y)

Например, f(m(25, g(14))) е валиден израз от горния тип и се оценява до 76, защото:

f(m(25,g(14))) =

f( min( 25, (14 mod 5)!) =

f (min (25, 24)) =

(24 * 24) mod 100 = 76

Даден е текстови файл с последователен достъп, в който са записани на отделен ред цяло
положително число N и след него пак на отделни редове N на брой изрази от горния вид.
Съдържанието на един примерен файл би бил:

3

f(15)

m(f(15),24)

f(m(25, g(14)))

Да се напише програма, която прочита информацията от един такъв файл и извежда на
стандартния изход на отделен ред всеки израз от файла и съответната му крайна оценка (без
междинни стъпки)
