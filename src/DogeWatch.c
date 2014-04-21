#include "pebble.h"
#include <time.h>
#include "DogeWatch.h"

//stuff

//For random text position
int rand_w, rand_w2;
int rand_h, rand_h2;

//For random text words
int rand_text1, rand_text1_2;
int rand_text2, rand_text2_2;

const char *random_texts1[5] =
{
  "much",
  "wow",
  "very",
  "so",
  "such"
};

const char *random_texts2[5] =
{
  "time",
  "doge",
  "hour",
  "tick",
  "watch"
};

static void set_random_colors()
{
  if ((rand_w + rand_h) % 2 == 0)
  {
    text_layer_set_text_color(random_text_layer, GColorWhite);
    text_layer_set_background_color(random_text_layer, GColorBlack);
  }else
  {
    text_layer_set_text_color(random_text_layer, GColorBlack);
    text_layer_set_background_color(random_text_layer, GColorWhite);
  }
}

static void set_random_colors2()
{
  if ((rand_w2 + rand_h2) % 2 == 0)
  {
    text_layer_set_text_color(random_text_layer_two, GColorWhite);
    text_layer_set_background_color(random_text_layer_two, GColorBlack);
  }else
  {
    text_layer_set_text_color(random_text_layer_two, GColorBlack);
    text_layer_set_background_color(random_text_layer_two, GColorWhite);
  }
}

static void refresh_date_text(struct tm* current_time)
{
  TextLayer *old_month_layer = month_text_layer;
  TextLayer *old_day_layer = day_text_layer;

  static char month[5];
  static char date[5];

  for(int i = 0; i<5; i++){
    month[i] = '\0';
    date[i] = '\0';
  }

  strftime(month, 5, "M %m", current_time);  
  strftime(date, 5, "D %d", current_time);

  month_text_layer = text_layer_create(GRect(2*(bounds.size.w)/4, 2*(bounds.size.h)/4, (bounds.size.w)/4, (bounds.size.h)/8));
  text_layer_set_text_alignment(month_text_layer, GTextAlignmentCenter);
  text_layer_set_font(month_text_layer, comic_sans);
  text_layer_set_overflow_mode(month_text_layer, GTextOverflowModeWordWrap);
  text_layer_set_text_color(month_text_layer, GColorWhite);
  text_layer_set_background_color(month_text_layer, GColorBlack);

  day_text_layer = text_layer_create(GRect(2*(bounds.size.w)/4, 2*(bounds.size.h)/4 + (bounds.size.h)/8, (bounds.size.w)/4, (bounds.size.h)/8));
  text_layer_set_text_alignment(day_text_layer, GTextAlignmentCenter);
  text_layer_set_font(day_text_layer, comic_sans);
  text_layer_set_overflow_mode(day_text_layer, GTextOverflowModeWordWrap);
  text_layer_set_text_color(day_text_layer, GColorWhite);
  text_layer_set_background_color(day_text_layer, GColorBlack);

  text_layer_set_text(month_text_layer, month);
  text_layer_set_text(day_text_layer, date);

  if(old_month_layer != NULL)
  {
    text_layer_destroy(old_month_layer);
  }
  if(old_day_layer != NULL)
  {
    text_layer_destroy(old_day_layer);
  }

  layer_add_child(window_layer, text_layer_get_layer(month_text_layer));
  layer_add_child(window_layer, text_layer_get_layer(day_text_layer));


}

static void refresh_random_text()
{
  TextLayer *old_layer = random_text_layer;

  rand_w = rand()%4;
  
  if(rand_w == 0 || rand_w == 3){
    rand_h = rand()%4;
  
  }
  else if(rand_w == 2){
    
    rand_h = rand()%2;
    
    if(rand_h == 1){    
      rand_h = 3;
    }
  }
  else{
    rand_h = 0;
  }

  rand_text1 = rand()%5;
  rand_text2 = rand()%5;



  random_text_layer = text_layer_create(GRect(rand_w * (bounds.size.w)/4,rand_h * (bounds.size.h)/4, (bounds.size.w)/4, (bounds.size.h)/4));
  text_layer_set_text_alignment(random_text_layer, GTextAlignmentCenter);
  text_layer_set_font(random_text_layer, comic_sans);
  text_layer_set_overflow_mode(random_text_layer, GTextOverflowModeWordWrap);
  set_random_colors();

  static char word[11];

  for(int i = 0; i<11; i++){
    word[i] = '\0';
  }

  strcpy(word, random_texts1[rand_text1]);
  strcat(word, " ");
  strcat(word, random_texts2[rand_text2]);



  text_layer_set_text(random_text_layer, word);

  if(old_layer != NULL)
  {
    text_layer_destroy(old_layer);
  }

  layer_add_child(window_layer, text_layer_get_layer(random_text_layer));

}

static void refresh_random_text2()
{
  TextLayer *old_layer = random_text_layer_two;

  rand_w2 = rand()%4;
  while(rand_w2 == rand_w){  
    rand_w2 = rand()%4;
  }

  if(rand_w2 == 0 || rand_w2 == 3){
    rand_h2 = rand()%4;
    while(rand_h2 == rand_h){
      rand_h2 = rand()%4;
    }
  
  }
  else if(rand_w2 == 2){
    rand_h2 = rand()%2;
    if(rand_h2 == 1){
      rand_h2 = 3;
    }
    while(rand_h2 == rand_h){
      rand_h2 = rand()%2;
      if(rand_h2 == 1){
        rand_h2 = 3;
      }
    }
  }
  else{
    rand_h2 = 0;
  }



  rand_text1_2 = rand()%5;
  while(rand_text1 == rand_text1_2){
    rand_text1_2 = rand()%5;
  }
  
  int rand_text2_2 = rand()%5;
  while(rand_text2 == rand_text2_2){
    rand_text2_2 = rand()%5;
  }




  random_text_layer_two = text_layer_create(GRect(rand_w2 * (bounds.size.w)/4,rand_h2 * (bounds.size.h)/4, (bounds.size.w)/4, (bounds.size.h)/4));
  text_layer_set_text_alignment(random_text_layer_two, GTextAlignmentCenter);
  text_layer_set_font(random_text_layer_two, comic_sans);
  text_layer_set_overflow_mode(random_text_layer_two, GTextOverflowModeWordWrap);
  set_random_colors2();

  static char word2[11];

  for(int i = 0; i<11; i++){
    word2[i] = '\0';
  }

  strcpy(word2, random_texts1[rand_text1_2]);
  strcat(word2, " ");
  strcat(word2, random_texts2[rand_text2_2]);


  text_layer_set_text(random_text_layer_two, word2);

  if(old_layer != NULL)
  {
    text_layer_destroy(old_layer);
  }

  layer_add_child(window_layer, text_layer_get_layer(random_text_layer_two));

}


static void refresh_invert()
{
  if(invert_screen == 1)
  {
    invert_screen = 0;
    InverterLayer *old_layer = window_invert_layer;
    window_invert_layer = inverter_layer_create(bounds);
    if (old_layer != NULL)
    {
      inverter_layer_destroy(old_layer);
    }

  }else{
    invert_screen = 1;
    layer_add_child(window_layer, inverter_layer_get_layer(window_invert_layer));
  }
}

static void refresh_day_of_week(struct tm* current_time)
{
  static char d_o_w[20];

  for (int i = 0; i < 20; ++i)
  {
    d_o_w[i] = '\0';
  }

  int day_of_week = current_time->tm_wday;

  switch(day_of_week){

    case 0 :
      strcpy(d_o_w, "SUN");
      break;
    case 1 :
      strcpy(d_o_w, "MON");
      break;
    case 2 :
      strcpy(d_o_w, "TUE");
      break;
    case 3 :
      strcpy(d_o_w, "WED");
      break;
    case 4 :
      strcpy(d_o_w, "THU");
      break;
    case 5 :
      strcpy(d_o_w, "FRI");
      break;
    case 6 :
      strcpy(d_o_w, "SAT");
      break;
    default :
      strcpy(d_o_w, "ERR");
  }

  text_layer_set_text(day_of_week_text_layer, d_o_w);
}

static void refresh_battery(BatteryChargeState charge_state)
{
  static char battery_text[] = "Chrg";

  GBitmap *old_image = battery_image;

  if (charge_state.is_charging)
  {
    battery_image = gbitmap_create_with_resource(RESOURCE_ID_DOGE_CHARGING);

  } else if(charge_state.charge_percent > 90)
  {
    battery_image = gbitmap_create_with_resource(RESOURCE_ID_DOGE_CHARGING);

  } else if (charge_state.charge_percent <= 90 && charge_state.charge_percent >= 70)
  {
    battery_image = gbitmap_create_with_resource(RESOURCE_ID_DOGE_90_TO_70);

  } else if (charge_state.charge_percent < 70 && charge_state.charge_percent >= 40)
  {
    battery_image = gbitmap_create_with_resource(RESOURCE_ID_DOGE_60_TO_40);

  } else if (charge_state.charge_percent < 40 && charge_state.charge_percent >= 10)
  {
    battery_image = gbitmap_create_with_resource(RESOURCE_ID_DOGE_30_TO_10);

  } else if (charge_state.charge_percent < 10)
  {
    battery_image = gbitmap_create_with_resource(RESOURCE_ID_DOGE_DEAD);

  }

  if (!charge_state.is_charging)
  {
    snprintf(battery_text, sizeof(battery_text), "%d%%", charge_state.charge_percent);
  }

  bitmap_layer_set_bitmap(battery_image_layer, battery_image);
  if(old_image != NULL)
  {
    gbitmap_destroy(old_image);
  }

  text_layer_set_text(battery_text_layer, battery_text);

}

// Called once per minute
static void handle_minute_tick(struct tm* tick_time, TimeUnits units_changed)
{
  static char time_text [] = "00:00";

  static char temp1[3];
  static char temp2[3];

  for (int i = 0; i < 3; ++i)
  {
    temp1[i] = temp2[i] = '\0';
  }

  strftime(time_text, sizeof(time_text), "%R", tick_time);

  strncpy(temp1, time_text, 2);
  int temp1_int = atoi(temp1);

  if(!clock_is_24h_style()){
    //12 hour mode
    if (temp1_int > 12)
    {
      temp1_int -= 12;
    }else if(temp1_int == 0)
    {
      temp1_int = 12;
    }
  }

  snprintf(temp1, 3,"%d", temp1_int);
  strncpy(temp2, time_text + 3, 2);



  text_layer_set_text(time_hour_text_layer, temp1);
  text_layer_set_text(time_min_text_layer, temp2);

  refresh_battery(battery_state_service_peek());
  refresh_day_of_week(tick_time);
  refresh_random_text();
  refresh_random_text2();
  refresh_date_text(tick_time);
  //inverts the whole screen
  refresh_invert();
}

static void init(void)
{
  //load font
  comic_sans = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_COMIC_SANS_12));

  srand(time(0));
  window = window_create();
  const bool animated = true;
  window_stack_push(window, animated);

  window_layer = window_get_root_layer(window);
  //GRect that represents the entire screen
  bounds = layer_get_frame(window_layer);

  //creates the inverter layer to be used to flip the screen every min
  window_invert_layer = inverter_layer_create(bounds);
  invert_screen = 0;

  set_up_background();
  /*
  *   TIME
  */

  set_up_time();
  layer_add_child(window_layer, text_layer_get_layer(time_hour_text_layer));
  layer_add_child(window_layer, text_layer_get_layer(time_min_text_layer));

  /*
  *
  */
  /**************************************/
  /*
  *   BATTERY
  */

  set_up_battery();
  layer_add_child(window_layer, text_layer_get_layer(battery_text_layer));
  layer_add_child(window_layer, bitmap_layer_get_layer(battery_image_layer));

  /*
  *
  */
  /**************************************/
  /*
  *   DATE
  */

  set_up_day_of_week();
  layer_add_child(window_layer, text_layer_get_layer(day_of_week_text_layer));

  /*
  *
  */
  /**************************************/
  /*
   *  RANDOM TEXT
  */

  set_up_random_text();
  set_up_random_text2();

  /*
   *
  */
  /**************************************/
  /*
  *   MONTH AND DAY
  */

  set_up_date();


  /*
  *
  */
  /**************************************/
  /*
  *   Tick Tock
  */

  time_t now = time(NULL);
  struct tm *current_time = localtime(&now);
  handle_minute_tick(current_time, MINUTE_UNIT);
  tick_timer_service_subscribe(MINUTE_UNIT, &handle_minute_tick);

  /*
  *
  */

}

static void deinit(void)
{
  //Month Text Destroy
  text_layer_destroy(month_text_layer);

  //Day Text Destroy
  text_layer_destroy(day_text_layer);

  //Random Text Destroy
  text_layer_destroy(random_text_layer);
  text_layer_destroy(random_text_layer_two);

  //Window Invert Destroy
  inverter_layer_destroy(window_invert_layer);

  //Date Destroy
  text_layer_destroy(day_of_week_text_layer);

  //Battery Destroy
  bitmap_layer_destroy(battery_image_layer);
  gbitmap_destroy(battery_image);
  text_layer_destroy(battery_text_layer);

  //Time Destroy
  text_layer_destroy(time_min_text_layer);
  text_layer_destroy(time_hour_text_layer);

  //Background Destroy
  inverter_layer_destroy(doge_invert_layer);
  bitmap_layer_destroy(doge_background_image_layer);
  gbitmap_destroy(doge_background_image);

  //Window Destroy
  window_destroy(window);

  fonts_unload_custom_font(comic_sans);
}

int main(void)
{
  init();
  app_event_loop();
  deinit();
}
