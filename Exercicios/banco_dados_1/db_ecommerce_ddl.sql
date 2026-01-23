CREATE TABLE tb_categorias (
	id_categoria SERIAL NOT NULL,
	nom_categoria VARCHAR(25) NOT NULL,
	PRIMARY KEY (id_categoria)
);

CREATE TABLE tb_clientes (
	id_cliente SERIAL NOT NULL,
	nom_cliente VARCHAR(100) NOT NULL,
	num_telefone INT,
	dsc_email VARCHAR(50) NOT NULL,
	dsc_endereco VARCHAR(150) NOT NULL,
	PRIMARY KEY (id_cliente)
);

CREATE TABLE tb_produtos (
	id_produto SERIAL NOT NULL,
	nom_produto VARCHAR(100) NOT NULL,
	dsc_produto VARCHAR(500),
	vlr_produto NUMERIC(6, 2),
	nom_marca VARCHAR(20) NOT NULL,
	PRIMARY KEY (id_produto)
);

CREATE TABLE tb_pedidos (
	id_pedido SERIAL NOT NULL,
	vlr_total NUMERIC(7, 2) NOT NULL,
	dsc_forma_pagamento VARCHAR(7) NOT NULL,
	data_entrega DATE NOT NULL,
	data_pedido DATE NOT NULL,
	id_cliente INT NOT NULL,
	PRIMARY KEY (id_pedido),
	FOREIGN KEY (id_cliente) REFERENCES tb_clientes(id_cliente)
);

CREATE TABLE tb_produtos_categorias (
	id_prod_cat SERIAL NOT NULL,
	id_produto INT NOT NULL,
	id_categoria INT NOT NULL,
	PRIMARY KEY (id_prod_cat),
	FOREIGN KEY (id_categoria) REFERENCES tb_categorias(id_categoria),
	FOREIGN KEY (id_produto) REFERENCES tb_produtos(id_produto)
);


CREATE TABLE tb_itens (
	id_item SERIAL NOT NULL,
	id_pedido INT NOT NULL,
	num_quantidade INT NULL,
	id_produto INT NOT NULL,
	PRIMARY KEY (id_item, id_pedido),
	FOREIGN KEY (id_pedido) REFERENCES tb_pedidos(id_pedido)
		ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (id_produto) REFERENCES tb_produtos(id_produto)
);
