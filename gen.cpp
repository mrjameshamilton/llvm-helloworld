
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

using namespace llvm;

int main() {
    LLVMContext C;
    Module M("helloworld", C);

    Function *main =
            Function::Create(FunctionType::get(Type::getInt32Ty(C), false),
                             GlobalValue::ExternalLinkage, "main", M);

    IRBuilder B(C);

    BasicBlock *entry = BasicBlock::Create(C, "entry", main);
    B.SetInsertPoint(entry);

    FunctionCallee printf = M.getOrInsertFunction(
            "printf", FunctionType::get(Type::getVoidTy(C),
                                        {PointerType::getUnqual(C)}, true));

    Value *string = B.CreateGlobalString("Hello, World!\n");

    B.CreateCall(printf, {string});

    B.CreateRet(B.getInt32(0));

    M.print(outs(), nullptr);

    return 0;
}
