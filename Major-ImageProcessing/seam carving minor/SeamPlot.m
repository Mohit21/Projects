function x=SeamPlot(x,SeamVector)
% SEAMPLOT takes as input an image and the SeamVector array and produces
% an image with the seam line superimposed upon the input image, x, for
% display purposes.

value=1.5*max(x(:));
for i=1:size(SeamVector,1)
    x(i,SeamVector(i))=value;
end

