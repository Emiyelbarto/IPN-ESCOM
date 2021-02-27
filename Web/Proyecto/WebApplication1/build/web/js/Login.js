$(document).ready(function (){
    limpiarCamposLogin();
    
    $('#btnIngresar').click(function (){
        validarLogin();
    });
    
    $('#txtUsuario').focus(function (){
        $('#txtUsuario').addClass("campoConFoco");
    });
    
    $('#txtUsuario').blur(function (){
        $('#txtUsuario').removeClass("campoConFoco").addClass("campoSinFoco");
    });
    
    $('#txtClave').focus(function (){
        $('#txtClave').addClass("campoConFoco"); 
    });
    
    $('#txtClave').blur(function (){
        $('#txtClave').removeClass("campoConFoco").addClass("campoSinFoco");
    });
});

function validarLogin(){
    var Usuario = $('#txtUsuario').val();
    var Password = $('#txtClave').val();
    
    if(Usuario == ""){
        alert("El campo Usuario no puede estar en blanco");
        $('#txtUsuario').focus();
    }
    else if(Password == ""){
        alert("El campo Contraseña no puede estar en blanco");
        $('#txtClave').focus();
    }
    else{
        $('#frmLogin').submit();
    }
}

function limpiarCamposLogin(){
    $('.textBox').val("");
}