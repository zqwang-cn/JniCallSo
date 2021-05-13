# Use JNI to call functions in .so/.dll files from Java code

## Steps

0. Prepare .so file to be called from Java code.

```bash
gcc -shared -fPIC -o libexample.so example.c
```

1. Declare a native function in .java file.

```java
public native static void jni_call_so(String s);
```

2. Generate JNI .h file.

```bash
javah JniCallSo
```

3. Create .c file and implement functions in JNI .h file. Call .so file of step 0.

```c
const char* str = (*env)->GetStringUTFChars(env, jstr, 0);
example(str)
```

4. Compile JNI .so file. Modify include path of JNI .h files if needed.

```bash
gcc -I/usr/lib/jvm/java-8-openjdk-amd64/include -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux -shared -fPIC -o libjnicallso.so JniCallSo.c libexample.so
```

5. Load JNI .so file in .java file.

```java
static {
    System.load("/absolute/path/to/JniCallSo/libjnicallso.so");
}
```

6. Compile .java file.

```bash
javac JniCallSo.java
```

7. Run .class file.

```bash
java JniCallSo
```