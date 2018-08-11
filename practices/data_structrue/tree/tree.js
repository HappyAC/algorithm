class TreeNode{
    constructor(data){
        this.data=data;
        this.left=null;
        this.right=null;
    }
}

let root = new TreeNode('A');
//      1
//     2  3
//    4
//   5  6
// pre order: 1245;;6;;;3;; 
let i = 0;
function createTree(pre_order_str) { 
    if(i>pre_order_str.length) return;
    if(pre_order_str[i]===';') return;
    CreateTree(pre_order_str,i++);
}
function CreateTree(pre_order_str) { 
    i=0;
    createTree(pre_order_str);
}

// Make an instance of two and place it on the page.
var elem = document.body;
var params = { width: 285, height: 200 };
var two = new Two(params).appendTo(elem);

// two has convenience methods to create shapes.
var circle = two.makeCircle(72, 100, 50);
var rect = two.makeRectangle(213, 100, 100, 100);

// The object returned has many stylable properties:
circle.fill = '#FF8000';
circle.stroke = 'orangered'; // Accepts all valid css color
circle.linewidth = 5;

rect.fill = 'rgb(0, 200, 255)';
rect.opacity = 0.75;
rect.noStroke();

// Don't forget to tell two to render everything
// to the screen
two.update();