
import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!



public class UrlValidatorTest extends TestCase {


    public UrlValidatorTest(String testName) {
        super(testName);
    }



    public void testManualTest()
    {

        //Initial Manual test

        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        // URL formulation:
        // Object[] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};



        System.out.println("Testing URLs \n");


        //Expect true
        String url1 = "http://www.yahoo.com";
        boolean result1 = urlVal.isValid(url1);

        System.out.print(url1);
        if(result1 == true)
            System.out.println("\t------ UrlVali: True. | Test valid");
        else
            System.out.println("\t------ UrlVali: True. | Test failed");


        //Expect false
        String url2 = "http://256.256.256.256";
        boolean result2 = urlVal.isValid(url2);

        System.out.print(url2);
        if(result2 == false)
            System.out.println("\t------ UrlVali: False. | Test valid");
        else
            System.out.println("\t------ UrlVali: True. | Test failed");

        //Expect false
        String url3 = "http://1.2.3.4.5";
        boolean result3 = urlVal.isValid(url3);

        System.out.print(url3);
        if(result3 == false)
            System.out.println("\t------ UrlVali: False. | Test valid");
        else
            System.out.println("\t------ UrlVali: True. | Test failed");

        //Expect false
        String url4 = "http://:80";
        boolean result4 = urlVal.isValid(url4);

        System.out.print(url4);
        if(result4 == false)
            System.out.println("\t------ UrlVali: False. | Test valid");
        else
            System.out.println("\t------ UrlVali: True. | Test failed");

        //Expect true
        String url5 = "ftp://www.google.com/";
        boolean result5 = urlVal.isValid(url5);

        System.out.print(url5);
        if(result5 == false)
            System.out.println("\t------ UrlVali: False. | Test valid");
        else
            System.out.println("\t------ UrlVali: True. | Test failed");

    }


    public void testYourFirstPartition()
    {
        //Partition #1
        //A number of manual testing items were failed in partition one.

        //This partition takes apart each URL string and runs them through the test,
        //A new component is added after the previous component passes all thest,
        //to ensure that the bug was only caused by the additional NEW component.


        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        assertTrue(urlVal.isValid("http://")); //note: ftp:// crashes
        String[] invalidURL1 = { "://",
                "http:",
                "http/",
                "http:/",
                "3ht://",
                "httttttttp",
                "httttttttp:/",
                "ftp:/",
        }; //last one serves as a control


        System.out.println("Testing IR UrlSchemes");
        for( int x = 0; x < invalidURL1.length; x++) {

            boolean resultsPartition = urlVal.isValid(invalidURL1[x]);

            if (resultsPartition == true && invalidURL1[x] != "http://") {
                System.out.println("Incorrect Test detected : " + invalidURL1[x]);
            }

        }
        System.out.println("================================================================");


        String validScheme = "http://";
        assertTrue(urlVal.isValid(validScheme));
        String[] invalidURL2 = { "256.256.256.256",
                "1.2.3.4.5",
                "1.2.3",
                "1.2.3.4.",
                ".1.2.3.4",
                "go.a",
                "go.a1a",
                "go.1aa",
                "aaa.",
                "aaa",
                ""};


        System.out.println("Input Partition: CR UrlSchemes + IR UrlAuthorities");
        for( int y = 0; y < invalidURL2.length; y++) {

            String url1_url2 = validScheme + invalidURL2[y];

            boolean resultsPartition1_2 = urlVal.isValid(url1_url2);

            if (resultsPartition1_2 == true) {
                System.out.println("Incorrect Test detected : " + url1_url2);
            }

        }
        System.out.println("================================================================");

        String validAuthority = "http://0.0.0.0";
        assertTrue(urlVal.isValid(validAuthority));
//     String[] invalidURL3 = { ":-1",
//                              ":65636",
//                              ":65a"};

        String[] invalidURL3 = {
                "",
                ":80",
                ":65535",
                ":0"};


        System.out.println("Input Partition: CR UrlSchemes + CR UrlAuthorities + IR Ports");
        for( int y = 0; y < invalidURL3.length; y++) {

            String url1_url2_url3 =  validAuthority + invalidURL3[y];

            boolean resultsPartition = urlVal.isValid(url1_url2_url3);

            if (resultsPartition == false) {
                System.out.println("Incorrect Test detected : " + url1_url2_url3);


            }

        }
        System.out.println("================================================================");


        String validPort = ""; //Stephanie: Any other non-null parts are incorrectly marked as false!!
        assertTrue(urlVal.isValid(validAuthority + validPort));
        String[] invalidURL4 = { "/..",
                "/../",
                "/..//file",
                "/test1//file"};

        System.out.println("Input Partition: CR UrlSchemes + CR UrlAuthorities + CR Ports + IR Paths");
        for( int y = 0; y < invalidURL4.length; y++) {

            String url1_url2_url3_url4 = validScheme + validAuthority + validPort +  invalidURL4[y];

            boolean resultsPartition = urlVal.isValid(url1_url2_url3_url4);

            if (resultsPartition == true) {
                System.out.println("Incorrect Test detected : " + url1_url2_url3_url4);
            }

        }
        System.out.println("================================================================");




    }

    public void testYourSecondPartition(){
        //Partitioning input #2
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        String[] schemas = {"http://", "ftp://"};
        String[] authority = {"www.google.com", "www.google.com?key=value1", "www.engadget.com"};
        for(int i=0; i < schemas.length; i++){
            for(int j=0; j < authority.length; j++) {
                assert(urlVal.isValid(schemas[i] + authority[j]));
            }
        }
    }


    public void testIsValid()
    {
        //You can use this function for programming based testing
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        String[] schema = {"http://", "://", "rand", "ran://", "h3t://"};
        String[] body = {"www.google.com", "www.google.net", "www.google.co"};
        String[] end = {"?", "?key=value"};

        for(int i=0;i < schema.length; i++){
            for(int j= 0; j < body.length; j++){
                for(int k=0; k < end.length; k++){
                    boolean testBool = urlVal.isValid(schema[i] + body[j] + end[k]);
                    if(testBool == true)
                    System.out.printf(schema[i] + body[j] + end[k] + "\n");
                }
            }
        }
    }




}
