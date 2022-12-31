class getset {
  
 String name;

   // setter method
//param ctt u init

   void setName( String name ) {
       this.name = name;
   }

   // getter method

   String getName(){
       return this.name;
   }

   public static void main( String[] args ) {
      getset obj = new getset();

       // calling the setter and the getter method
       obj.setName("Toshiba");
       System.out.println("obj.name: "+obj.getName());
   }
}