
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

using namespace llvm;

int main() {
    LLVMContext C;
    Module M("helloworld", C);

    // Create the `int main()` function, which is the entry point to the Hello
    // World application.
    Function *main =
            Function::Create(FunctionType::get(Type::getInt32Ty(C), false),
                             GlobalValue::ExternalLinkage, "main", M);

    IRBuilder B(C);

    // We need to an entry a basic block to the function, where we'll insert
    // instructions.
    BasicBlock *entry = BasicBlock::Create(C, "entry", main);
    B.SetInsertPoint(entry);

    // Get the libc puts function declaration.
    FunctionCallee puts = M.getOrInsertFunction(
            "puts", FunctionType::get(Type::getInt32Ty(C),
                                      {PointerType::getUnqual(C)}, false));

    // Create a null-terminated global string.
    Value *string = B.CreateGlobalString("Hello, World!");

    B.CreateCall(puts, {string});

    B.CreateRet(B.getInt32(0));

    M.print(outs(), nullptr);

    return 0;
}
