#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkWidget *window; // janela principal
    gtk_init(&argc, &argv); // inicializa o GTK

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // cria uma janela

    gtk_widget_show(window); // mostra a janela

    gtk_main(); // loop principal

    return 0;
}
