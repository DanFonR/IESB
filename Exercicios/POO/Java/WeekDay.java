import java.util.Scanner;

class CustomDate {

  private byte day;
  private byte month;
  private int year;
  
  private boolean isLeap;

  Date(byte day, byte month, int year) {
    
    int dateValidity = checkDate(day, month, year);
    
    switch (dateValidity) {

      case -1:
        System.err.println("Invalid day");
        System.exit(1);
        break;

      case -2:
        System.err.println("Invalid month");
        System.exit(1);
        break;

      case -12:
        System.err.println("Invalid day and month");
        System.exit(1);
        break;

      default:
        this.isLeap = (dateValidity == 1)? true : false;
        break;
    }

    this.day = day;
    this.month = month;
    this.year = year;
  }

  private static int checkDate(byte day, byte month, int year) {
    
    boolean Leap = (year % 4 == 0) && ((year % 400 == 0) || (y % 100 != 0));
    int errcode = Leap? 1 : 0;

    if (month > 12 || month == 0)
      errcode = -2;

    if (  (month % 2 == 1 && month < 8 && day > 31)
       || (month % 2 == 0 && month > 8 && day > 30)
       || (Leap && month == 2 && day > 29)
       || (!Leap && month == 2 && day > 28)
       || (day == 0))
      errcode = (errcode < 0)? -1 : -12;

    return errcode;
  }
}

class WeekDay {
  
  public static void main(String[] args) {
    
  }
}
