// Java program to demonstrate forName() method

public class Test {
	public static void main(String[] args)
		throws ClassNotFoundException
	{
		// get the Class instance using forName method
		Class c1 = Class.forName("java.lang.String");
		Class i1 = Class.forName("java.lang.Integer");
		System.out.println("Class c1 = Class.forName(\"java.lang.String\");");
		System.out.println("Class i1 = Class.forName(\"java.lang.Integer\");");
		System.out.println("Class represented by variable c1 using c1.toString(): "
		+ c1.toString() );
		System.out.println("Class represented by variable i1 using i1.toString(): "
		+ i1.toString() );
		
		java.lang.String s1 = "Hello World";
		System.out.println("String variable s1=\"Hello World\" with output s1.toString() is " 
		+ s1.toString() );
	}
}
