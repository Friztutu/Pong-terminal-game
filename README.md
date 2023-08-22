<p align="center">
      <img src="https://i.ibb.co/CK88DD1/pngegg.png" width="420">
</p>

## О проекте

Игра pong реализованная на языке Си, с использованием стандартных библиотек и ncurses для отображение графики в терминале. Доступен режим для двух игроков или режим игры против компьютера.
С течением раунда скорость игры будет постепенно расти, под игровым полем можно найти delay, чем он ниже, чем выше скорость происходящего в терминале. Размеры игрового поля 80 на 25.
По идеи компьютер даже можно выиграть, я добавил легкую погрешность в его движениях, но это будет до невозможности сложно. В Makefile можно найти задачу на тесты стиль кода и cppcheck. 

## Превью
<img src="https://i.ibb.co/5cx9g6Z/2023-08-23-00-06-17.png" width="100%">

## Запуск
1. Скачать ncurses
 ```bash
   sudo apt-get install libncurses5-dev libncursesw5-dev
 ```
2. Команда для компила и запуска игры для двоих:
```bash
make for_two
../build/for_two
```
3. Команда для компила и запуска игры для одного:<br>
```bash
make for_one
../build/for_one
```

## Разработчик:

- [Alex](https://github.com/Friztutu)

## License

Project Pong-terminal-game is distributed under the MIT licence
