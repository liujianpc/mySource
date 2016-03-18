importjavax.swing.*;  
classGreetings{  
publicstaticvoidmain(String[]args){  
StringfullName;  
fullName=JOptionPane.showInputDialog(null,"Whatisyourname?");  JOptionPane.showMessageDialog(null,"Nicetomeetyou,"+fullName+".");  
System.exit(0);  
}  
}  