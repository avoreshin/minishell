# minishell

 ## Основная часть
| Program name     |minishell|
|------------------|---------|
| Turn in files    | Makefile, *.h, *.c |
| Makefile         |NAME, all, clean, fclean, re|
| Arguments        |
| External functs. | readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history,printf, malloc, free, write, access, open, read,close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
| Libft authorized |Yes|
| Description      |Write a shell|

  ##Функции:

- Отображение подсказки при ожидание новой команды
- Иметь рабочую историю 
- Поиск и запуск нужного исполняемого файла (на основе переменной PATH или с использованием
  относительный или абсолютный путь).
- Не используйте более одной глобальной переменной.
- Не интерпретировать незакрытые кавычки или специальные символы, которые не требуются в данной теме, такие как \ (обратная косая черта) или ; (точка с запятой).
  например \ (обратная косая черта) или ; (точка с запятой).
- Обработка ' (одинарная кавычка), которая должна предотвратить интерпретацию оболочкой метасимволов в кавычках.
- Обработайте " (двойную кавычку), которая не позволит оболочке интерпретировать метасимволы в кавычках, кроме $ (знака доллара).
- Реализуйте перенаправления:
  ◦ < должен перенаправлять вход.
  ◦ > должен перенаправлять вывод.
  ◦ << должен быть задан разделитель, а затем считывать входные данные до тех пор, пока не появится строка, содержащая разделитель.
  разделитель. Однако, он не должен обновлять историю!
  ◦ >> должен перенаправлять вывод в режиме добавления.
- Реализуйте конвейеры (символ |). Выход каждой команды в трубопроводе
  соединяется с входом следующей команды с помощью трубы.
- Обрабатывать переменные окружения ($, за которым следует последовательность символов), которые
  должны расширяться до своих значений.
- Обрабатывать $?, которые должны расширяться до состояния выхода последней выполненной команды.
  конвейера переднего плана.
- Обработка ctrl-C, ctrl-D и ctrl-\, которые должны вести себя как в bash.
- В интерактивном режиме:
  ◦ ctrl-C выводит новое приглашение на новую строку.
  ◦ ctrl-D выходит из оболочки.
  ◦ ctrl-\ ничего не делает.
- Ваша оболочка должна реализовывать следующие встроенные функции:
  ◦ echo с опцией -n
  ◦ cd только с относительным или абсолютным путем
  ◦ pwd без опций
  ◦ export без опций
  ◦ unset без опций
  ◦ env без опций и аргументов
  ◦ exit без опций
  Функция readline() может вызывать утечки памяти. Вы не обязаны их исправлять. Но
  это не означает, что ваш собственный код, да и код, который вы написали, может иметь утечки памяти
  утечки памяти.

| Func     |Description|
|----------|-----|
| readline |     |

| rl_clear_history, ||
| rl_on_new_line,   
| rl_replace_line,  
rl_redisplay,
add_history,
printf, 
malloc, 
free,
write,
access,
open,
read,
close, 
fork,
wait,
waitpid,
wait3,
wait4,
signal,
sigaction,
sigemptyset,
sigaddset,
kill,
exit,
getcwd,
chdir,
stat,
lstat,
fstat,
unlink,
execve,
dup,
dup2,
pipe,
opendir,
readdir,
closedir,
strerror,
perror,
isatty,
ttyname,
ttyslot,
ioctl,
getenv , 
tcsetattr,
tcgetattr,
tgetent,
tgetflag,
tgetnum,
tgetstr,
tgoto,
tputs