#include <stdio.h>
#include <stdlib.h>

//p/ implementar a comunicação através dos soquetes
#include <sys/socket.h>
//p/ manipular strings
#include <string.h>
//p/ funções de read/write
#include <fcntl.h>

#include <netinet/in.h>

#define porta 3456

int main(){
	//criação do soquete:
	//domain: AF_INET: IPv4/6
	//type: SOCK_DGRAM (datagrama): para comunicação através do protcl. UDP
	//protocol: 0: protocolo default (nesse caso UDP)
	int retorno_socket = socket(AF_INET, SOCK_DGRAM, 0);
	//retorna >0 se não deu erro, -1 se deu erro
	if(retorno_socket < 0){
		printf("%s\n", "erro na criação do soquete");
		exit(0);
	}
	
	//configurar soquete:
	//socket_descriptor: retorno do soquete
	//level: SOL_SOCKET: especifica o nível do protocolo (camada de transporte)
	//option_name: SO_BROADCAST: permite o envio de mensagens entre cliente/servidor
	//value_of_option: endereço que contém o nome da opção
	//option_lenght: tamanho da variável option_name
	int option_value = 1; //para habilitar a opção
	int estado = setsockopt(retorno_socket, SOL_SOCKET, SO_BROADCAST, &option_value, sizeof(option_value));
	//retorna >0 se não deu erro, -1 se deu erro	
	if(estado < 0){
		printf("%s\n", "erro ao configurar o soquete");
		exit(0);
	}
	
	//struct para manipulação de endereços de internet:
	//sin_family: "família" do endereço
	//sin_port: porta a ser utilizada; htons: host to network short
	//sin_addr.s_addr: endereço a ser utilizado; INADDR_ANY: qualquer interface livre
	struct sockaddr_in endr_servidor;
	endr_servidor.sin_family = AF_INET;
	endr_servidor.sin_port = htons(porta);
	endr_servidor.sin_addr.s_addr = INADDR_ANY;

	//bind: vincula o soquete dadas as configurações
	estado = bind(retorno_socket, (struct sockaddr*)&endr_servidor, sizeof(struct sockaddr));
	if(estado < 0){
		printf("%s\n","erro ao vincular soquete às interfaces de internet");
		exit(0);
	}
	
	
}
