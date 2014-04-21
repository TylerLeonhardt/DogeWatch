#ifndef DOGEWATCH_H
#define DOGEWATCH_H
#include "pebble.h"

//Main Window
static Window *window;
static Layer *window_layer;

//Background
static GBitmap *doge_background_image;
static BitmapLayer *doge_background_image_layer;
static InverterLayer *doge_invert_layer;


//Time
static TextLayer *time_hour_text_layer;
static TextLayer *time_min_text_layer;

//Battery
static TextLayer *battery_text_layer;
static GBitmap *battery_image;
static BitmapLayer *battery_image_layer;

//Date
static TextLayer *day_of_week_text_layer;

//Random Text
static TextLayer *random_text_layer;

//Random Text2
static TextLayer *random_text_layer_two;

//Month Day
static TextLayer *month_text_layer;
static TextLayer *day_text_layer;

static InverterLayer *window_invert_layer;
int invert_screen;

const int NUM_OF_ROWS_OR_COLS = 4;

//Comic Sans font
GFont comic_sans;

//GRect that represents the entire screen
GRect bounds;

static void set_up_background()
{

  //load doge image
  doge_background_image = gbitmap_create_with_resource(RESOURCE_ID_DOGE);

  //loop through for a full grid of checkerboard doges
  for (int i = 0; i < NUM_OF_ROWS_OR_COLS; ++i)
  {
    for (int j = 0; j < NUM_OF_ROWS_OR_COLS; ++j)
    {

      //Creates Doge rect
      GRect temp = GRect(i * (bounds.size.w)/4, j * (bounds.size.h)/4, (bounds.size.w)/4, (bounds.size.h)/4);
      doge_background_image_layer = bitmap_layer_create(temp);
      bitmap_layer_set_bitmap(doge_background_image_layer, doge_background_image);
      bitmap_layer_set_alignment(doge_background_image_layer, GAlignCenter);
      layer_add_child(window_layer, bitmap_layer_get_layer(doge_background_image_layer));

      //adds an inverter layer for checkerboard style
      if ((i + j) % 2 == 0)
      {
        doge_invert_layer = inverter_layer_create(temp);
        layer_add_child(window_layer, inverter_layer_get_layer(doge_invert_layer));
      }
    }
  }

}

static void set_up_time()
{
  time_hour_text_layer = text_layer_create(GRect(1*(bounds.size.w)/4, 1*(bounds.size.h)/4, (bounds.size.w)/4 /* width */, (bounds.size.h)/4 /* height */));
  text_layer_set_text_color(time_hour_text_layer, GColorWhite);
  text_layer_set_background_color(time_hour_text_layer, GColorBlack);
  text_layer_set_text_alignment(time_hour_text_layer,GTextAlignmentCenter);
  text_layer_set_font(time_hour_text_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_COMIC_SANS_25)));

  time_min_text_layer = text_layer_create(GRect(2*(bounds.size.w)/4, 1*(bounds.size.h)/4, (bounds.size.w)/4 /* width */, (bounds.size.h)/4 /* height */));
  text_layer_set_text_color(time_min_text_layer, GColorBlack);
  text_layer_set_background_color(time_min_text_layer, GColorWhite);
  text_layer_set_text_alignment(time_min_text_layer,GTextAlignmentCenter);
  text_layer_set_font(time_min_text_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_COMIC_SANS_25)));

}

static void set_up_battery()
{
  battery_text_layer = text_layer_create(GRect(1*(bounds.size.w)/4, 2*(bounds.size.h)/4 + (bounds.size.h)/8, (bounds.size.w)/4 /* width */, (bounds.size.h)/8 /* height */));
  text_layer_set_text_color(battery_text_layer, GColorBlack);
  text_layer_set_background_color(battery_text_layer, GColorWhite);
  text_layer_set_text_alignment(battery_text_layer, GTextAlignmentCenter);
  text_layer_set_font(battery_text_layer, comic_sans);
  text_layer_set_overflow_mode(battery_text_layer, GTextOverflowModeWordWrap);

  battery_image = gbitmap_create_with_resource(RESOURCE_ID_DOGE);

  battery_image_layer = bitmap_layer_create(GRect(1*(bounds.size.w)/4, 3*(bounds.size.h)/4, (bounds.size.w)/4 /* width */, (bounds.size.h)/4 /* height */));
  bitmap_layer_set_alignment(battery_image_layer, GAlignCenter);
  bitmap_layer_set_bitmap(battery_image_layer, battery_image);
}

static void set_up_day_of_week()
{
  day_of_week_text_layer = text_layer_create(GRect(1*(bounds.size.w)/4, 2*(bounds.size.h)/4, (bounds.size.w)/4 /* width */, (bounds.size.h)/8 /* height */));
  text_layer_set_text_color(day_of_week_text_layer, GColorBlack);
  text_layer_set_background_color(day_of_week_text_layer, GColorWhite);
  text_layer_set_text_alignment(day_of_week_text_layer,GTextAlignmentCenter);
  text_layer_set_font(day_of_week_text_layer, comic_sans);
}

static void set_up_random_text()
{
  random_text_layer = text_layer_create(GRect(0,0, (bounds.size.w)/4, (bounds.size.h)/4));
  text_layer_set_text_alignment(random_text_layer, GTextAlignmentCenter);
  text_layer_set_font(random_text_layer, comic_sans);
  text_layer_set_overflow_mode(random_text_layer, GTextOverflowModeWordWrap);
}

static void set_up_random_text2()
{
  random_text_layer_two = text_layer_create(GRect(0,0, (bounds.size.w)/4, (bounds.size.h)/4));
  text_layer_set_text_alignment(random_text_layer_two, GTextAlignmentCenter);
  text_layer_set_font(random_text_layer_two, comic_sans);
  text_layer_set_overflow_mode(random_text_layer_two, GTextOverflowModeWordWrap);

}

static void set_up_date()
{
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
}

#endif
