#include <stdio.h>
#include <string.h>	
	
int main()
{
	char ctrl_ipaddr[25],temp_options[25],wlan_options[25],wlan_sub_option_1[10],wlan_sub_option_2[10];

	char str[] = "127.0.0.1#1#123#ssid";
	char delim[] = "#";
	int option_num=0;

	printf("Original String == %s\n",str);
        char *ptr = strtok(str, delim);
        //Separate IP Address of controller from WLAN Command
        strcpy(ctrl_ipaddr,ptr);
        while (ptr != NULL)
        {
		ptr = strtok(NULL,delim);

		switch(option_num)
		{
			case 0:	{
					strcpy(wlan_options,ptr);
					++option_num;
					break;
				}

			case 1:	{
                	                strcpy(wlan_sub_option_1,ptr);
                        	        ++option_num;
                        	        break;		
				}
	
	        	case 2: {
	                                strcpy(wlan_sub_option_2,ptr);
	                                ++option_num;
	                                break;
				}
		}
                //ptr = strtok(NULL, delim);
       	}
	
        printf("Parsed Strings == %s, %s, %s and %s\n",ctrl_ipaddr,wlan_options,wlan_sub_option_1,wlan_sub_option_2);

	return 0;
}
