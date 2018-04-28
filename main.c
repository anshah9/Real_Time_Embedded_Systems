 /* SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <sensor.h>
#include <misc/printk.h>
#include <misc/__assert.h>
#include <stdio.h>
#include <string.h>


void main(void){

	struct device *temp_dev;
	// long long c,c1,a;
	int i=0;

	printk("---------------Inside main------------\n");

	temp_dev = device_get_binding("HCSR0");
	if (!temp_dev) {
		printf("error: no temp device\n");
		return;
	}

	printk("temp device is %p, name is %s\n",
	       temp_dev, temp_dev->config->name);

	// c = _tsc_read();
	// k_sleep(1);
	// c1 = _tsc_read();
	// a = c1 - c;
	// printf("1 mili is %lld \n", a);

	// c = _tsc_read();
	// k_sleep(1);
	// c1 = _tsc_read();
	// a = c1 - c;
	// printf("1 mili is %lld \n", a);
	
	// c = _tsc_read();
	// k_sleep(1);
	// c1 = _tsc_read();
	// a = c1 - c;
	// printf("1 mili is %lld \n", a);
	
	k_sleep(3000);

	//while (1) {
		int r;
		struct sensor_value temp_value;

		r = sensor_sample_fetch(temp_dev);
		if (r) {
			printf("sensor_sample_fetch failed return: %d\n", r);
			return;
		}

		r = sensor_channel_get(temp_dev, SENSOR_CHAN_TEMP,
				       &temp_value);
		if (r) {
			printf("sensor_channel_get failed return: %d\n", r);
			return;
		}

		printk("End of main in loop %d \n\n",i);

		i++;

		k_busy_wait(1000000);
	//}
}
