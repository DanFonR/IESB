class MainArgs {

  public static void main(String[] args) {

    System.out.println("loop for normal");
    
    for (int i = 0; i < args.length; i++)
      System.out.printf("arg[%d]: %s\n", i, args[i]);

    System.out.println("\nloop for each");
    
    for (String arg : args)
      System.out.println("Argumento: " + arg);
  }
}