#include <gtk/gtk.h>

/* Explicações e comentários
 * static: variáveis e funções estáticas só podem ser acessadas dentro do arquivo
 * onde foram declaradas. Isso é útil para evitar conflitos de nomes.
 * O static é opcional, mas é uma boa prática usá-lo.
 * static serve para definir o escopo de uma variável ou função.
 * 
 * GtkWidget: é o tipo de dados que representa um widget (componente gráfico)
 * do GTK. Todos os widgets são derivados de GtkWidget.
 * gpointer: é um ponteiro genérico. É usado para passar ponteiros de qualquer
 * tipo para funções.
 * gpointer é um typedef para void*.
 * gpointer data: é um ponteiro para dados. É usado para passar dados para 
 * funções de callback.
 * 
 * g_print: é uma função de impressão do GTK. É equivalente ao printf.
 * 
*/

static void hello(GtkWidget *widget, gpointer data)
{
    g_print("Hello World\n");
}

/**
 * gboolean: é um tipo de dados do GTK. É equivalente a um int.
 * gboolean é um typedef para int.
 * gboolean serve para definir o tipo de retorno de funções de callback.
 * 
 * GdkEvent: é um tipo de dados do GTK. É equivalente a um ponteiro void.
 * GdkEvent é um typedef para void*.
 * GdkEvent serve para definir o tipo de dados do parâmetro event de funções
 * de callback.
 * *event: é um ponteiro para um evento. É usado para passar eventos para
 * funções de callback. 
 * 
 */
static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
    g_print("delete event occurred\n");
    /* Mude TRUE para FALSE e a janela principal será destruída com um
      * "delete_event". */
    return FALSE;
}

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
    /**
     * gtk_main_quit: é uma função do GTK que encerra o loop principal do GTK.
     * É equivalente a um return 0.
     */
}

int main(int *argc, int *argv[]) {
    GtkWidget *window;
    GtkWidget *button;
    /**
     * GtkWidget *window: é um ponteiro para um widget do tipo GtkWindow.
     * GtkWidget *button: é um ponteiro para um widget do tipo GtkButton.
     */

    gtk_init (&argc, &argv);
    /* Esta função é chamada em todas as aplicações GTK. Argumentos da linha
     * de comando são interpretados e retornados à aplicação. 
    */

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    /**
     * gtk_window_new: é uma função do GTK que cria uma nova janela.
     * 
    */

    g_signal_connect(window, "delete_event", G_CALLBACK(delete_event), NULL);
    /**
     * g_signal_connect: é uma função do GTK que conecta uma função de callback
     * a um sinal.
     * 
     * window: é o widget que emite o sinal.
     * "delete_event": é o nome do sinal.
     * G_CALLBACK(delete_event): é a função de callback.
     * G_CALLBACK: é um macro do GTK que converte uma função de callback em um
     * ponteiro para função de callback.
     * NULL: é um ponteiro para dados. É usado para passar dados para funções
    */

    g_signal_connect(G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);
    /**
     * @brief g_signal_connect: é uma função do GTK que conecta uma função de callback
     * a um sinal.
     * G_OBJECT (window): é o widget que emite o sinal.
     * "destroy": é o nome do sinal.
     * G_OBJECT: é um macro do GTK que converte um widget em um ponteiro para
     * GObject.
     * 
     * G_CALLBACK (destroy): é a função de callback.
     * G_CALLBACK: é um macro do GTK que converte uma função de callback em um
     * ponteiro para função de callback.
     * 
     * 
    */

    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    /**
     * gtk_container_set_border_width: é uma função do GTK que define a largura
     * da borda de um container.
     * 
     * GTK_CONTAINER(window): é o container.
     * 10: é a largura da borda.
    */
    
    gtk_window_set_title(GTK_WINDOW(window), "Janela");
    /**
     * @brief gtk_window_set_title: é uma função do GTK que define o título de
     * uma janela.
     * 
     * GTK_WINDOW(window): é a janela.
    */
    button = gtk_button_new_with_label("Hello World");

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(hello), NULL);
    /* Quando o botão recebe o sinal "clicked", chamará a função hello()
     * passando NULL como argumento. hello() é definida acima.
     * G_CALLBACK: é um macro do GTK que converte uma função de callback em um
     * ponteiro para função de callback.
    */
    g_signal_connect_swapped(G_OBJECT (button), "clicked",
 	            G_CALLBACK (gtk_widget_destroy),
                G_OBJECT (window));
    /* Isso fará com que a janela será destruída pela chamada
      * gtk_widget_destroy(window) quando o botão for clicado ("clicked").
      * Novamente, o sinal destroy poderia vir daqui ou do gerenciador
      * de janelas. 
    */

    gtk_container_add(GTK_CONTAINER(window), button);
    /* Isto empacota o botão na janela (um recipiente gtk). 
     * gtk_container_add: é uma função do GTK que adiciona um widget a um
     * container.
    */

    gtk_widget_show(button);
    /* exibe o botão criado */
    gtk_widget_show(window);
    /* exibe a janela criada */

    gtk_main();
    /* Toda aplicação GTK deve ter uma chamada gtk_main(). O controle
     * termina aqui e espera por um evento (como um apertamento de tecla
     * ou evento do mouse). 
    */
}

