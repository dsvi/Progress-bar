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
Supports Unixes and Windows.

To use, just copy it over to your project. It only depends on [`coformat`](https://github.com/dsvi/coformat/tree/main) library.

Or you can add it to your `CMakeLists.txt` through [`CPM.cmake`](https://github.com/cpm-cmake/cpm.cmake)

```cmake
CPMAddPackage("gh:dsvi/coformat#main")
CPMAddPackage("gh:dsvi/progress-bar#main")
```