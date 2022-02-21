public class SP_Assignment3 {
    public static void main(String[] args) {

    }

    public long strtoint(String ip ){
        ip = "163.58.99.15";
        String[] arr = ip.split(".");
        int[] numarr = new int[arr.length];
        for (int i =0; i<arr.length; i++){
            numarr[i] = Integer.parseInt(arr[i]);
        }

        long num = numarr[0] + numarr[1]*256 +numarr[2]*256*256 + numarr[3]*256*256*256;
        return num;
    }
    public String inttostr(long num) {
        String ip = "";
        ip = ip + String.valueOf(num%256);
        num = num/256;
        ip = ip + String.valueOf(num%256);
        num = num/256;
        ip = ip + String.valueOf(num%256);
        num = num/256;
        ip = ip + String.valueOf(num%256);
        return ip;
    }

    public void Question2(){
        String[][] table = {{"Macahine name 1","63.255.173.183","00-1A-3F-F1-4C-C6"},
                {"Macahine name 2","172.16.254.16","9C-35-5B-5F-4C-D7"},
                {"Macahine name 3","216.58.216.164","10-F0-05-40-F3-22"}};

//        	Machine Name to IP
        String machinename = "Macahine name 1";
        for (int i =0;i <table[0].length; i++){
            if( table[i][0] == machinename){
                System.out.println(table[i][1]);
            }
        }
//	IP to Machine Name
        String ip = "216.58.216.164";
        for (int i =0;i <table[0].length; i++){
            if( table[i][1] == ip){
                System.out.println(table[i][0]);
            }
        }
//	IP to MAC
        for (int i =0;i <table[0].length; i++){
            if( table[i][1] == ip){
                System.out.println(table[i][2]);
            }
        }
//	MAC to IP

        String mac = "9C-35-5B-5F-4C-D7";
        for (int i =0;i <table[0].length; i++){
            if( table[i][2] == mac){
                System.out.println(table[i][1]);
            }
        }
    }

}
