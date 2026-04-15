// Copyright (c) 2026 BYK. All Rights Reserved.
//
// This file is part of BaseCalc.
//
// BaseCalc is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, under version 2 of the License.
//
// BaseCalc is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with BaseCalc. If not, see <https://www.gnu.org/licenses/>.
//
// Maintainer: BYK <bykdev@proton.me>

#include "BaseCalc.h"

typedef struct {
    GtkWidget *window;
    GtkWidget *convertFrom;
    GtkWidget *convertTo;
    GtkWidget *input;
    GtkWidget *output;
} PassWidgets;

void set_base(GtkButton *button, gpointer data)
{
    const char *str = gtk_button_get_label(GTK_BUTTON (button));
    gtk_menu_button_set_label(GTK_MENU_BUTTON (data), str);
}

void convert_dec_2_base_X(GtkButton *button, gpointer data)
{
    PassWidgets *widgetStruct = (PassWidgets *)data;
    const char *from = gtk_menu_button_get_label(GTK_MENU_BUTTON (widgetStruct->convertFrom));
    const char *to = gtk_menu_button_get_label(GTK_MENU_BUTTON (widgetStruct->convertTo));
    const char *str2Convert = gtk_entry_buffer_get_text(gtk_entry_get_buffer(GTK_ENTRY (widgetStruct->input)));
    GtkAlertDialog *alert;
    bool dec2bX = false;
    int base;
    int dstBase;
    char baseStr[32] = {0};
    if (strcmp(to, from) == 0)
    {
	alert = gtk_alert_dialog_new("Converting from %s base to %s base, pointless.\n", to, from);
	gtk_alert_dialog_show(GTK_ALERT_DIALOG (alert), GTK_WINDOW (widgetStruct->window));
	return;
    }
    else
    {
	if (strcmp(from, "Binary") == 0)
	{
	    base = 2;
	    if (strcmp(to, "Decimal") == 0)
	    {
		snprintf(baseStr, sizeof(baseStr), "%d", baseX2Dec(2, str2Convert, strlen(str2Convert)));
		printf("%s\n", str2Convert);
		gtk_button_set_label(GTK_BUTTON (widgetStruct->output), baseStr);
	    }
	    else if (strcmp(to, "Octal") == 0)
	    {
		dstBase = 8;
		bin2BaseX(str2Convert, dstBase, baseStr);
		gtk_button_set_label(GTK_BUTTON (widgetStruct->output), baseStr);
	    }
	    else if (strcmp(to, "Hexadecimal") == 0)
	    {
		dstBase = 16;
		bin2BaseX(str2Convert, dstBase, baseStr);
		gtk_button_set_label(GTK_BUTTON (widgetStruct->output), baseStr);
	    }
	    else
	    {
		alert = gtk_alert_dialog_new("How did you even get here?\n");
		gtk_alert_dialog_show(GTK_ALERT_DIALOG (alert), GTK_WINDOW (widgetStruct->window));
		return;
	    }
	}
	else if (strcmp(from, "Octal") == 0)
	{
	    base = 8;
	    if (strcmp(to, "Decimal") == 0)
	    {
		snprintf(baseStr, sizeof(baseStr), "%d", baseX2Dec(base, str2Convert, strlen(str2Convert)));
		gtk_button_set_label(GTK_BUTTON (widgetStruct->output), baseStr);
	    }
	    else if (strcmp(to, "Binary") == 0)
	    {
		dstBase = 2;
		baseX2Bin(base, str2Convert, baseStr);
		gtk_button_set_label(GTK_BUTTON (widgetStruct->output), baseStr);
	    }
	    else
	    {
		alert = gtk_alert_dialog_new("Currently %s Conversion is limited to base 10 only.\n", from);
		gtk_alert_dialog_show(GTK_ALERT_DIALOG (alert), GTK_WINDOW (widgetStruct->window));
		return;
	    }
	}
	else if (strcmp(from, "Decimal") == 0)
	{
	    dec2bX = true;
	    int value = atoi(str2Convert);
	    char outputString[32] = {0};
	    if (strcmp(to, "Binary") == 0)
	    {
		base = 2;
	    }
	    else if (strcmp(to, "Octal") == 0)
	    {
		base = 8;
	    }
	    else if (strcmp(to, "Hexadecimal") == 0)
	    {
		base = 16;
	    }
	    else
	    {
		alert = gtk_alert_dialog_new("Now, how did you get here?\n");
		gtk_alert_dialog_show(GTK_ALERT_DIALOG (alert), GTK_WINDOW (widgetStruct->window));
		return;
	    }
	    dec2BaseX(base, value, outputString);
	    gtk_button_set_label(GTK_BUTTON (widgetStruct->output), outputString);
	}
	else if (strcmp(from, "Hexadecimal") == 0)
	{
	    base = 16;
	    if (strcmp(to, "Decimal") == 0)
	    {
		snprintf(baseStr, sizeof(baseStr), "%d", baseX2Dec(base, str2Convert, strlen(str2Convert)));
		gtk_button_set_label(GTK_BUTTON (widgetStruct->output), baseStr);
	    }
	    else if (strcmp(to, "Binary") == 0)
	    {
		dstBase = 2;
		baseX2Bin(base, str2Convert, baseStr);
		gtk_button_set_label(GTK_BUTTON (widgetStruct->output), baseStr);
	    }
	    else
	    {
		alert = gtk_alert_dialog_new("Currently %s Conversion is limited to base 10 only.\n", from);
		gtk_alert_dialog_show(GTK_ALERT_DIALOG (alert), GTK_WINDOW (widgetStruct->window));
		return;
	    }
	}
	else
	{
	    alert = gtk_alert_dialog_new("Unrecognized Option: %s\n", from);
	    gtk_alert_dialog_show(GTK_ALERT_DIALOG (alert), GTK_WINDOW (widgetStruct->window));
	    return;
	}
    }
}

void copy_output(GtkButton *button, gpointer data)
{
    const char *text = gtk_button_get_label(GTK_BUTTON (button));
    GdkClipboard *clipboard = gtk_widget_get_clipboard(GTK_WIDGET (button));
    gdk_clipboard_set_text(GDK_CLIPBOARD (clipboard), text);
}

PassWidgets widgets;

void activate (GtkApplication *app, gpointer data)
{
    GtkWidget *window = gtk_application_window_new(app);
    GtkWidget *grid = gtk_grid_new();

    GtkWidget *entryIn = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY (entryIn), "Input");
    GtkWidget *labelOut = gtk_button_new_with_label("Output");
    GtkWidget *convertBtn = gtk_button_new_with_label("Convert");
    
    GtkWidget *popUpSelection1 = gtk_menu_button_new();
    gtk_menu_button_set_always_show_arrow(GTK_MENU_BUTTON (popUpSelection1), TRUE);
    GtkWidget *popOver1 = gtk_popover_new();
    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);

    GtkWidget *bBtn1 = gtk_button_new_with_label("Binary");
    GtkWidget *oBtn1 = gtk_button_new_with_label("Octal");
    GtkWidget *dBtn1 = gtk_button_new_with_label("Decimal");
    GtkWidget *xBtn1 = gtk_button_new_with_label("Hexadecimal");

    GtkWidget *popUpSelection2 = gtk_menu_button_new();
    gtk_menu_button_set_always_show_arrow(GTK_MENU_BUTTON (popUpSelection2), TRUE);
    GtkWidget *popOver2 = gtk_popover_new();
    GtkWidget *box2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);

    GtkWidget *bBtn2 = gtk_button_new_with_label("Binary");
    GtkWidget *oBtn2 = gtk_button_new_with_label("Octal");
    GtkWidget *dBtn2 = gtk_button_new_with_label("Decimal");
    GtkWidget *xBtn2 = gtk_button_new_with_label("Hexadecimal");

    widgets.window = GTK_WIDGET (window);
    widgets.convertFrom = GTK_WIDGET (popUpSelection1);
    widgets.convertTo = GTK_WIDGET (popUpSelection2);
    widgets.input = GTK_WIDGET (entryIn);
    widgets.output = GTK_WIDGET (labelOut);

    gtk_window_set_title(GTK_WINDOW (window), "Base Calculator");
    gtk_window_set_default_size(GTK_WINDOW (window), 200, 250);

    gtk_entry_set_max_length(GTK_ENTRY (entryIn), 0);

    gtk_window_set_child(GTK_WINDOW (window), grid);

    gtk_popover_set_position(GTK_POPOVER (popOver1), GTK_POS_BOTTOM);
    gtk_menu_button_set_popover(GTK_MENU_BUTTON (popUpSelection1), GTK_WIDGET (popOver1));
    gtk_popover_set_child(GTK_POPOVER (popOver1), GTK_WIDGET (box1));

    gtk_box_append(GTK_BOX (box1), GTK_WIDGET (bBtn1));
    gtk_box_append(GTK_BOX (box1), GTK_WIDGET (oBtn1));
    gtk_box_append(GTK_BOX (box1), GTK_WIDGET (dBtn1));
    gtk_box_append(GTK_BOX (box1), GTK_WIDGET (xBtn1));

    gtk_popover_set_position(GTK_POPOVER (popOver2), GTK_POS_BOTTOM);
    gtk_menu_button_set_popover(GTK_MENU_BUTTON (popUpSelection2), GTK_WIDGET (popOver2));
    gtk_popover_set_child(GTK_POPOVER (popOver2), GTK_WIDGET (box2));

    gtk_box_append(GTK_BOX (box2), GTK_WIDGET (bBtn2));
    gtk_box_append(GTK_BOX (box2), GTK_WIDGET (oBtn2));
    gtk_box_append(GTK_BOX (box2), GTK_WIDGET (dBtn2));
    gtk_box_append(GTK_BOX (box2), GTK_WIDGET (xBtn2));

    gtk_grid_set_row_homogeneous(GTK_GRID (grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID (grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID (grid), 50);

    gtk_grid_attach(GTK_GRID (grid), entryIn, 1, 1, 2, 1);
    gtk_grid_attach(GTK_GRID (grid), labelOut, 6, 1, 2, 1);
    gtk_grid_attach(GTK_GRID (grid), popUpSelection1, 1, 4, 2, 1);
    gtk_grid_attach(GTK_GRID (grid), popUpSelection2, 6, 4, 2, 1);
    gtk_grid_attach(GTK_GRID (grid), convertBtn, 3, 6, 1, 1);

    g_signal_connect(GTK_BUTTON (labelOut), "clicked", G_CALLBACK (copy_output), NULL);

    g_signal_connect(GTK_BUTTON (bBtn1), "clicked", G_CALLBACK (set_base), popUpSelection1);
    g_signal_connect(GTK_BUTTON (oBtn1), "clicked", G_CALLBACK (set_base), popUpSelection1);
    g_signal_connect(GTK_BUTTON (dBtn1), "clicked", G_CALLBACK (set_base), popUpSelection1);
    g_signal_connect(GTK_BUTTON (xBtn1), "clicked", G_CALLBACK (set_base), popUpSelection1);

    g_signal_connect(GTK_BUTTON (bBtn2), "clicked", G_CALLBACK (set_base), popUpSelection2);
    g_signal_connect(GTK_BUTTON (oBtn2), "clicked", G_CALLBACK (set_base), popUpSelection2);
    g_signal_connect(GTK_BUTTON (dBtn2), "clicked", G_CALLBACK (set_base), popUpSelection2);
    g_signal_connect(GTK_BUTTON (xBtn2), "clicked", G_CALLBACK (set_base), popUpSelection2);

    g_signal_connect(GTK_BUTTON (convertBtn), "clicked", G_CALLBACK (convert_dec_2_base_X), &widgets);

    gtk_window_present(GTK_WINDOW (window));
}


int main(int argc, char **argv)
{
    GtkApplication *baseCalc = gtk_application_new("Base.Calculator", G_APPLICATION_DEFAULT_FLAGS);
    int status;

    g_signal_connect(G_APPLICATION(baseCalc), "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(baseCalc), argc, argv);

    g_object_unref(baseCalc);
    widgets.convertFrom = NULL;
    widgets.convertTo = NULL;
    widgets.input = NULL;
    widgets.output = NULL;

    return status;
}
