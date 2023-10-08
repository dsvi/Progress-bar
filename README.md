# progress-bar
A simple class to display progress bar on terminal.
Does nothing if redirected to a file.
Disappears when something else is printed to console.
Appears again on update() or show()

![animated example](example.png)

Simple example:

```C++
Progress_bar bar;
for (int i = bar.min; i < bar.max; ++i) {
	bar.update(i);
	this_thread::sleep_for(100ms);
	if (i == 50)
		cprintln("{fr}OOOPs! A warning has been reported.{fd}");
	if (i == 60)
		cprintln("But worry not, progress continues!");
}
cprintln("And disappears at the end.");
```

To use, just copy it over to your project. It only depends on `coformat` library.