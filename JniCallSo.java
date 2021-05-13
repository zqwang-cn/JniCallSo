public class JniCallSo {
    static {
        System.load("/absolute/path/to/JniCallSo/libjnicallso.so");
    }

    public native static void jni_call_so(String s);

    public static void main(String[] args) {
        jni_call_so("Hello so");
    }
}