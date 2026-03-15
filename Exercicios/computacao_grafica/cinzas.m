function [Y, err] = binarizar(X, limiar)
  Y = arrayfun(@(x) (x > limiar), X);
  err = sum((X - Y).^2) / sum(X.^2);
end

function Y = cromatizar(X)
  max_rgb = max(X, [], 3);
  Y = X.*(X == max_rgb);
end

function main(arquivo_imagem, limiar, indice_figura)
  if nargin < 3
    indice_figura = 1;
  end

  imagem = imread(arquivo_imagem);
  imagem_cinza = double(rgb2gray(imagem))/255;
  [imagem_binarizada erro] = binarizar(imagem_cinza, limiar);
  imagem_cromatizada = cromatizar(imagem);

  figure(indice_figura);
  subplot(2,1,1);
  imshow([imagem imagem_cromatizada]);
  title 'Figura Original e Cromatizada';

  subplot(2,1,2);
  imshow([imagem_cinza imagem_binarizada]);
  title(sprintf('Figura Escala de Cinza e Binarizada\n(Limiar %.2f, Erro %.2f%%)',limiar, erro * 100));
end

main();
