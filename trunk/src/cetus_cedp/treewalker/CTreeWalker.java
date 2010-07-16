package cetus.treewalker;

import java.util.*;

import cetus.hir.*;

/**
 * TreeWalker to convert a C parse tree to Cetus IR.
 */
public class CTreeWalker extends TreeWalker
{
  private HashMap<String,Integer> action_map;

  public CTreeWalker(String filename)
  {
    super(filename);
    action_map = new HashMap<String,Integer>(100);

    String nonterminals[] =
    {
      "abstract_declarator",
      "additive_expression",
      "and_expression",
      "argument_expression_list",
      "assignment_expression",
      "assignment_operator",
      "cast_expression",
      "compound_statement",
      "conditional_expression",
      "constant_expression",
      "declaration",
      "declaration_list",
      "declaration_specifiers",
      "declarator",
      "direct_abstract_declarator",
      "direct_declarator",
      "enum_specifier",
      "enumerator",
      "enumerator_list",
      "equality_expression",
      "exclusive_or_expression",
      "expression",
      "expression_statement",
      "function_definition",
      "inclusive_or_expression",
      "init_declarator",
      "init_declarator_list",
      "initializer",
      "initializer_list",
      "iteration_statement",
      "jump_statement",
      "labeled_statement",
      "logical_and_expression",
      "logical_or_expression",
      "multiplicative_expression",
      "parameter_declaration",
      "parameter_list",
      "parameter_type_list",
      "pointer",
      "postfix_expression",
      "primary_expression",
      "relational_expression",
      "selection_statement",
      "shift_expression",
      "simple_declaration",
      "specifier_qualifier_list",
      "statement",
      "statement_list",
      "storage_class_specifier",
      "struct_declaration",
      "struct_declaration_list",
      "struct_declarator",
      "struct_declarator_list",
      "struct_or_union",
      "struct_or_union_specifier",
      "translation_unit",
      "type_name",
      "type_qualifier",
      "type_qualifier_list",
      "type_specifier",
      "unary_expression",
      "unary_operator"
    };

    for (int i = 0; i < nonterminals.length; ++i)
      action_map.put("action_" + nonterminals[i], i + 1);
  }

  @SuppressWarnings("unchecked")
  protected List<Object> action_abstract_declarator(TreeNode root)
  {
    List<Object> list = new ArrayList<Object>();
    for (TreeNode n : root)
    {
      Object o = doAction(n);

      if (o instanceof List)
        list.addAll((List<Object>)o);
      else
        list.add(o);
    }

    return list;
  }
 
  protected Expression action_cast_expression(TreeNode root)
  {
    if (root.getChildCount() == 1)
      return (Expression)doAction(root.getChild(0));
    else
    {
      List<Specifier> list = this.<List<Specifier>>doAction(root.getChild(1));
      Expression expr = (Expression)doAction(root.getChild(3));

      return new Typecast(Typecast.NORMAL, list, expr);
    }
  }

  protected Expression action_constant_expression(TreeNode root)
  {
    return (Expression)doAction(root.getChild(0));
  }

  @SuppressWarnings("unchecked")
  protected Declarator action_declarator(TreeNode root)
  {
    ArrayList<Object> list = new ArrayList<Object>();
    for (TreeNode n : root)
    {
      Object o = doAction(n);
      if (o != null)
        list.add(o);
    }

    List<Specifier> pointer_specs  = new LinkedList<Specifier>();
    Object direct_decl = null;

    if (list.size() > 1)
    {
      pointer_specs = (List<Specifier>)list.get(0);
      direct_decl = list.get(1);
    }
    else
      direct_decl = list.get(0);

    if (direct_decl instanceof IDExpression)
    {
      if (pointer_specs == null)
        return new VariableDeclarator((IDExpression)direct_decl);
      else
        return new VariableDeclarator(pointer_specs, (IDExpression)direct_decl);
        
    }
    else
    {
      if (direct_decl instanceof List)
        root.printTree(0);

      Declarator decl = (Declarator)direct_decl;
      decl.getSpecifiers().addAll(pointer_specs);
      return decl;
    }
  }

  protected Object action_direct_abstract_declarator(TreeNode root)
  {
    if (root.getChild(0).getText().equals("["))
    {
      if (root.getChildCount() == 2)
        return new ArraySpecifier();
      else
        return new ArraySpecifier((Expression)doAction(root.getChild(1)));
    }

    throw new RuntimeException("unknown direct_abstract_declarator");
  }

  protected Object action_direct_declarator(TreeNode root)
  {
    /* direct_declarator -> IDENTIFIER */
    if (root.getChildCount() == 1)
      return new Identifier(root.getChild(0).getText());

    /* direct_declarator -> '(' declarator ')' */
    if (root.getChild(0).getText().equals("("))
      return new NestedDeclarator((Declarator)doAction(root.getChild(1)));

    Object direct_decl = doAction(root.getChild(0));

    /* direct_declarator -> direct_declarator '(' parameter_type_list_opt ')' */
    if (root.getChild(1).getText().equals("("))
    {
      if (root.getChildCount() == 4)
      {
        List<Declaration> params = this.<List<Declaration>>doAction(root.getChild(2));

        if (direct_decl instanceof NestedDeclarator)
        {
          for(Declaration d : params)
            ((NestedDeclarator)direct_decl).addParameter(d);
          return direct_decl;
        }
        else
          return new ProcedureDeclarator((IDExpression)direct_decl, this.<List<Declaration>>doAction(root.getChild(2)));
      }
      else
      {
        if (direct_decl instanceof NestedDeclarator)
          return direct_decl;
        else
          return new ProcedureDeclarator((IDExpression)direct_decl, new LinkedList<Declaration>());
      }
    }

    /* direct_declarator -> direct_declarator '[' constant_expression_opt ']' */
    if (root.getChild(1).getText().equals("["))
    {
      ArraySpecifier array_spec = null;
      if (root.getChildCount() == 4)
        array_spec = new ArraySpecifier((Expression)doAction(root.getChild(2)));
      else
        array_spec = new ArraySpecifier();

      if (direct_decl instanceof IDExpression)
        return new VariableDeclarator((IDExpression)direct_decl, array_spec);
      else // it's a VariableDeclarator
      {
        ((VariableDeclarator)direct_decl).getTrailingSpecifiers().add(array_spec);
        return direct_decl;
      } 
    }

    root.printTree(0);
    throw new RuntimeException("unknown direct declarator");
  }

  protected Object action_enum_specifier(TreeNode root)
  {
    String name = null;
    if (root.getChild(1).getText().equals("{"))
      name = "anonymous" + Integer.toString(anonymous_count++);
    else
      name = root.getChild(1).getText();

    List<Declarator> decl_list = null;
    int child_count = root.getChildCount();
    if (child_count > 2)
      decl_list = this.<List<Declarator>>doAction(root.getChild(child_count - 2));

    if (decl_list != null)
    {
      cetus.hir.Enumeration enum_decl = new cetus.hir.Enumeration(new Identifier(name), decl_list);
      saved_decl = enum_decl;
    }

    return new UserSpecifier(new Identifier("enum " + name));
  }

  protected Statement action_expression_statement(TreeNode root)
  {
    if (root.getChildCount() == 1)
      return new NullStatement();
    else  
      return new ExpressionStatement((Expression)doAction(root.getChild(0)));
  }

  protected Procedure action_function_definition(TreeNode root)
  {
    ArrayList<Object> list = new ArrayList<Object>();
    for (TreeNode n : root)
      list.add(doAction(n));

    List<Specifier> spec_list = this.<List<Specifier>>doAction(root.getChild(0));
    ProcedureDeclarator pd = this.<ProcedureDeclarator>doAction(root.getChild(1));
    CompoundStatement stmt = this.<CompoundStatement>doAction(root.getChild(2));

    return new Procedure(spec_list, pd, stmt); 
  }

  protected Declarator action_init_declarator(TreeNode root)
  {
    Declarator decl = (Declarator)doAction(root.getChild(0));

    if (root.getChildCount() > 1)
      decl.setInitializer((Initializer)doAction(root.getChild(2)));

    return decl;
  }

  protected Statement action_iteration_statement(TreeNode root)
  {
    String s = root.getChild(0).getText();

    if (s.equals("for"))
    {
      Statement init = (Statement)doAction(root.getChild(2));
      Expression condition = ((ExpressionStatement)doAction(root.getChild(3))).getExpression();
      
      Expression step = null;
      Statement body = null;

      if (root.getChildCount() == 6)
      {
        body = (Statement)doAction(root.getChild(5));
      }
      else
      {
        step = (Expression)doAction(root.getChild(4));
        body = (Statement)doAction(root.getChild(6));
      }

      return new ForLoop(init, condition, step, body);
    }
    else if (s.equals("while"))
    {
      Expression expr = (Expression)doAction(root.getChild(2));
      Statement stmt = (Statement)doAction(root.getChild(4));

      return new WhileLoop(expr, stmt);
    }
    else // "do"
    {
      Statement stmt = (Statement)doAction(root.getChild(1));
      Expression expr = (Expression)doAction(root.getChild(4));

      return new DoLoop(stmt, expr);
    }
  }

  protected Initializer action_initializer(TreeNode root)
  {
    if (root.getChildCount() == 1)
      return new Initializer((Expression)doAction(root.getChild(0)));
    else
      return new Initializer(this.<List<Traversable>>doAction(root.getChild(1)));
  }

  @SuppressWarnings("unchecked")
  protected VariableDeclaration action_parameter_declaration(TreeNode root)
  {
    List<Specifier> spec_list = action_declaration_specifiers(root.getChild(0));
    
    if (root.getChildCount() > 1)
    {
      Object o = doAction(root.getChild(1));

      if (o instanceof Declarator)
        return new VariableDeclaration(spec_list, (Declarator)o);
      else if (o instanceof List)
      {
        List<Object> list = (List<Object>)o;
        for (Object o2 : list)
        {
          if (o2 instanceof List)
            spec_list.addAll((List<Specifier>)o2);
          else
            spec_list.add((Specifier)o2);
        }

        return new VariableDeclaration(spec_list);
      }
      else
        throw new RuntimeException("unknown (possibly abstract) declarator");
    }
    else
      return new VariableDeclaration(spec_list);
  }

  protected List<?> action_parameter_type_list(TreeNode root)
  {
    List<Object> list = this.<List<Object>>doAction(root.getChild(0));

    if (root.getChildCount() == 1)
      return list;
    else
    {
      list.add(new VariableDeclaration(new VariableDeclarator(new Identifier("..."))));
      return list;
    }
  }

  protected List<?> action_pointer(TreeNode root)
  {
    List<Object> list = new LinkedList<Object>();

    PointerSpecifier ps = PointerSpecifier.UNQUALIFIED;

    if (root.getChildCount() > 1
        && root.getChild(1).getText().equals("type_qualifier_list"))
    {
      List<Specifier> tq_list = this.<List<Specifier>>doAction(root.getChild(1));
      int n = 0;

      if (tq_list.contains(Specifier.CONST))
        n = n + 1;
      if (tq_list.contains(Specifier.VOLATILE))
        n = n + 2;

      switch (n)
      {
        case 1:
          ps = PointerSpecifier.CONST;
          break;

        case 2:
          ps = PointerSpecifier.VOLATILE;
          break;

        case 3:
          ps = PointerSpecifier.CONST_VOLATILE;
          break;

        default:
          ps = PointerSpecifier.UNQUALIFIED;
          break;
      }
    }

    if (root.getChild(root.getChildCount() - 1).getText().equals("pointer"))
    {
      list = this.<List<Object>>doAction(root.getChild(root.getChildCount() - 1));
    }

    list.add(0, ps);

    return list;
  }

  protected Expression action_postfix_expression(TreeNode root)
  {
    Expression expr = (Expression)doAction(root.getChild(0));

    if (root.getChildCount() == 1)
      return expr;
    else
    {
      String s = root.getChild(1).getText();

      if (s.equals("."))
        return new AccessExpression(expr, AccessOperator.MEMBER_ACCESS,
          new Identifier(root.getChild(2).getText()));
      else if (s.equals("->"))
        return new AccessExpression(expr, AccessOperator.POINTER_ACCESS,
          new Identifier(root.getChild(2).getText()));
      else if (s.equals("["))
      {
        Expression index = (Expression)doAction(root.getChild(2));

        if (expr instanceof ArrayAccess)
        {
          ((ArrayAccess)expr).addIndex(index);
          return expr;
        }
        else
          return new ArrayAccess(expr, index);
      }
      else if (s.equals("++"))
        return new UnaryExpression(UnaryOperator.POST_INCREMENT, expr);
      else if (s.equals("--"))
        return new UnaryExpression(UnaryOperator.POST_DECREMENT, expr);
      else if (s.equals("("))
      {
        if (root.getChildCount() == 4)
          return new FunctionCall(expr, this.<List<Expression>>doAction(root.getChild(2)));
        else
          return new FunctionCall(expr);
      }
    }

    throw new RuntimeException("unknown postfix expression");
  }

  protected Expression action_primary_expression(TreeNode root)
  {
    String s = root.getChild(0).getText();

    if (s.equals("string_literal_list"))
    {
      List<String> list = action_string_literal_list(root.getChild(0));

      String actual_string = "";

      for (String lit : list)
      {
        /* The extra backslash-quotes here are because the graphviz
           file format requires escape sequences for quotes.  The
           StringLiteral class automatically prints quotes around
           itself, so both backslashes and outer quotes need
           to be removed. */
        actual_string += lit.substring(2, lit.length() - 2);      
      }

      return new StringLiteral(actual_string);
    }
    else if (Character.isDigit(s.charAt(0)))
    {
      if (s.contains("."))
        return new FloatLiteral(Double.parseDouble(s));
      else
      {
        String suffix = "";

        int i = s.length() - 1;
        for ( ; i >= 0; --i)
        {
          char ch = s.charAt(i);

          /* keep skipping suffix letters but watch
             out for hexadecimal numbers  */

          if (Character.isDigit(ch))
            break;

          if ((ch >= 'a' && ch <= 'f')
              || (ch >= 'A' && ch <= 'F'))
            break;
        }

        suffix = s.substring(i + 1); 
        s = s.substring(0, i + 1);

        if (suffix.equals(""))
          return new IntegerLiteral(Long.decode(s));
        else
          return new IntegerLiteral(Long.decode(s), suffix);
      }
    }
    else if (s.equals("("))
    {
      return (Expression)doAction(root.getChild(1));
    }
    else
      return new Identifier(s);
  }

  protected Declaration action_simple_declaration(TreeNode root)
  {
    List<Specifier> spec_list = action_declaration_specifiers(root.getChild(0));

    List<Declarator> decl_list = null;

    if (root.getChildCount() == 3)
      decl_list = this.<List<Declarator>>doAction(root.getChild(1));

    if (decl_list == null)
      return new VariableDeclaration(spec_list);
    else
      return new VariableDeclaration(spec_list, decl_list);
  }

  protected Declaration action_struct_declaration(TreeNode root)
  {
    List<Specifier> spec_list = this.<List<Specifier>>doAction(root.getChild(0));
    List<Declarator> decl_list = this.<List<Declarator>>doAction(root.getChild(1));

    return new VariableDeclaration(spec_list, decl_list);
  }

  @SuppressWarnings("unchecked")
  protected List<Declaration> action_struct_declaration_list(TreeNode root)
  {
    List<Declaration> list = new LinkedList<Declaration>();

    if (root.hasChildren())
    {
      for (TreeNode n : root)
      {
        Object o = doAction(n);
        if (o != null)
        {
          try {
            list = (List<Declaration>)o;
          } catch (ClassCastException e) {
            if (saved_decl != null)
            {
              list.add(saved_decl);
              saved_decl = null;
            }
            list.add((Declaration)o);
          }
        }
      }
    }

    return list;
  }

  protected Declarator action_struct_declarator(TreeNode root)
  {
    return action_declarator(root.getChild(0));
  }

  protected ClassDeclaration action_struct_or_union_specifier(TreeNode root)
  {
    String key_text = root.getChild(0).getChild(0).getText();
    boolean forward_decl = (root.getChildCount() == 2);

    String name = null;
    if (!root.getChild(1).getText().equals("{"))
      name = root.getChild(1).getText();
    else
      name = "anonymous" + Integer.toString(anonymous_count++);

    ClassDeclaration cd = null;
    if (key_text.equals("struct"))
      cd = new ClassDeclaration(ClassDeclaration.STRUCT, new Identifier(name), forward_decl);
    else
      cd = new ClassDeclaration(ClassDeclaration.UNION, new Identifier(name), forward_decl);

    List<Declaration> decl_list = null;
    int child_count = root.getChildCount();
    if (child_count > 3)
    {
      decl_list = this.<List<Declaration>>doAction(root.getChild(child_count - 2));

      for (Declaration d : decl_list)
        cd.addDeclaration(d);
    }

    return cd;
  }

  protected List<?> action_type_name(TreeNode root)
  {
    List<Object> list = this.<List<Object>>doAction(root.getChild(0));
    if (root.getChildCount() > 1)
      list.addAll(this.<List<Object>>doAction(root.getChild(1)));
    return list;
  }

  protected Specifier action_type_qualifier(TreeNode root)
  {
    return Specifier.fromString(root.getChild(0).getText());
  }

  protected Specifier action_type_specifier(TreeNode root)
  {
    String s = root.getChild(0).getText();
    Specifier spec = Specifier.fromString(s);

    if (spec != null)
      return spec;

    if (s.equals("struct_or_union_specifier"))
    {
      ClassDeclaration cd = action_struct_or_union_specifier(root.getChild(0));
      saved_decl = cd;
      return new UserSpecifier(new Identifier(cd.getKey() + " " + cd.getName()));
    }
    else if (s.equals("enum_specifier"))
      return (Specifier)action_enum_specifier(root.getChild(0));
    else
      return new UserSpecifier(new Identifier(s));
  }

  protected Expression action_unary_expression(TreeNode root)
  {
    if (root.getChildCount() == 1)
      return (Expression)doAction(root.getChild(0));
    else if (root.getChild(0).getText().equals("sizeof"))
    {
      if (root.getChildCount() == 2)
        return new SizeofExpression((Expression)doAction(root.getChild(1)));
      else
        return new SizeofExpression(this.<List<Specifier>>doAction(root.getChild(2)));
    }
    else if (root.getChild(0).getText().equals("unary_operator"))
    {
      UnaryOperator op = UnaryOperator.fromString(root.getChild(0).getChild(0).getText());
      return new UnaryExpression(op, (Expression)doAction(root.getChild(1)));
    }

    throw new RuntimeException("unknown unary expression");
  }

  @SuppressWarnings("unchecked")
  protected <T> T doAction(TreeNode root)
  {
    int action_code = -1;

    try {
      action_code = action_map.get("action_" + root.getText());
    } catch (NullPointerException e) {
      return null;
    }

    switch (action_code)
    {
      case 2:  // additive_expression
      case 3:  // and_expression
      case 20: // equality_expression
      case 21: // exclusive_or_expression
      case 25: // inclusive_or_expression
      case 33: // logical_and_expression
      case 34: // logical_or_expression
      case 35: // multiplicative_expression
      case 42: // relational_expression
      case 44: // shift_expression
        return (T)defaultBinaryExpressionAction(root);

      case 4:  // argument_expression_list
      case 19: // enumerator_list
      case 27: // init_declarator_list
      case 29: // initializer_list
      case 37: // parameter_list
      case 46: // specifier_qualifier_list
      case 48: // statement_list
      case 53: // struct_declarator_list
      case 59: // type_qualifier_list
        return (T)defaultListAction(root);

      case 1:
        return (T)action_abstract_declarator(root);
      case 5:
        return (T)action_assignment_expression(root);
      case 7:
        return (T)action_cast_expression(root);
      case 8:
        return (T)action_compound_statement(root);
      case 9:
        return (T)action_conditional_expression(root);
      case 10:
        return (T)action_constant_expression(root);
      case 11:
        return (T)action_declaration(root);
      case 12:
        return (T)action_declaration_list(root);
      case 13:
        return (T)action_declaration_specifiers(root);
      case 14:
        return (T)action_declarator(root);
      case 15:
        return (T)action_direct_abstract_declarator(root);
      case 16:
        return (T)action_direct_declarator(root);
      case 18:
        return (T)action_enumerator(root);
      case 22:
        return (T)action_expression(root);
      case 23:
        return (T)action_expression_statement(root);
      case 24:
        return (T)action_function_definition(root);
      case 26:
        return (T)action_init_declarator(root);
      case 28:
        return (T)action_initializer(root);
      case 30:
        return (T)action_iteration_statement(root);
      case 31:
        return (T)action_jump_statement(root);
      case 32:
        return (T)action_labeled_statement(root);
      case 36:
        return (T)action_parameter_declaration(root);
      case 38:
        return (T)action_parameter_type_list(root);
      case 39:
        return (T)action_pointer(root);
      case 40:
        return (T)action_postfix_expression(root);
      case 41:
        return (T)action_primary_expression(root);
      case 43:
        return (T)action_selection_statement(root);
      case 45:
        return (T)action_simple_declaration(root);
      case 47:
        return (T)action_statement(root);
      case 49:
        return (T)action_specifier(root);
      case 50:
        return (T)action_struct_declaration(root);
      case 51:
        return (T)action_struct_declaration_list(root);
      case 52:
        return (T)action_struct_declarator(root);
      case 56:
        return (T)action_translation_unit(root);
      case 57:
        return (T)action_type_name(root);
      case 58:
        return (T)action_type_qualifier(root);
      case 60:
        return (T)action_type_specifier(root);
      case 61:
        return (T)action_unary_expression(root);

      default:
        root.printTree(0);
        throw new RuntimeException("action " + action_code + " not implemented");
    }
  }

  public TranslationUnit run(TreeNode root)
  {
    return action_translation_unit(root);
  }
}
